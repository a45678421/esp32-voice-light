#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "475";         // ← 替換為你的 WiFi 名稱
const char* password = "123456787";     // ← 替換為你的 WiFi 密碼

const int ledPin = 2;            // ← 你接 LED 的腳位（建議 GPIO2, GPIO13, GPIO5 等支援 PWM）
const int pwmFreq = 5000;         // 頻率 5kHz
const int pwmResolution = 8;      // 解析度 8-bit (0~255)

WebServer server(80);

void setup() {
  Serial.begin(115200);
  delay(100);

  // ✅ 設定 PWM（新版 API）
  ledcAttach(ledPin, pwmFreq, pwmResolution);
  ledcWrite(ledPin, 0);  // 預設關燈

  // ✅ WiFi 連線
  Serial.print("連接中，WiFi：");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\n✅ WiFi 已連線！");
  Serial.print("📶 IP 位址：");
  Serial.println(WiFi.localIP());

  // ✅ HTTP 路由
  server.on("/", []() {
    server.send(200, "text/plain", "ESP32 is ready!");
  });

  server.on("/on", []() {
    ledcWrite(ledPin, 255); // 最亮
    Serial.println("🟢 收到 /on，已開燈（255）");
    server.send(200, "text/plain", "💡 LED 已開啟");
  });

  server.on("/off", []() {
    ledcWrite(ledPin, 0); // 關燈
    Serial.println("🔴 收到 /off，已關燈（0）");
    server.send(200, "text/plain", "🛑 LED 已關閉");
  });

  server.on("/brightness", []() {
    if (server.hasArg("value")) {
      int brightness = server.arg("value").toInt();
      brightness = constrain(brightness, 0, 255); // 限制在 0~255
      ledcWrite(ledPin, brightness);
      Serial.printf("🌕 收到 /brightness：亮度設定為 %d\n", brightness);
      server.send(200, "text/plain", "✅ 亮度已設為 " + String(brightness));
    } else {
      server.send(400, "text/plain", "⚠️ 缺少參數 value");
    }
  });

  server.begin();
  Serial.println("🌐 HTTP Server 已啟動");
}

void loop() {
  server.handleClient();
}
