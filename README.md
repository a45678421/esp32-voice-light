# 💡 ESP32 Voice Light Controller

一個結合語音辨識與滑桿介面的智慧燈控系統，使用 ESP32 接收控制指令，透過 WiFi 網路與 PWM 控制 LED 的開關與亮度，支援語音與瀏覽器端雙模式控制。

---

## 🎯 專案特色

- ✅ 透過語音指令控制開燈、關燈、調整亮度  
- ✅ 支援網頁端滑桿即時調光  
- ✅ ESP32 WebServer 直連，不需額外伺服器  
- ✅ 支援中文語音辨識（Web Speech API）  
- ✅ 使用 PWM 精準控制 LED 亮度  

---

## 📦 系統架構

使用者（網頁端） → 語音 / 滑桿指令（網頁程式：HTML + JS） → HTTP 請求（on/off/brightness）（ESP32） → PWM 訊號（LED）

---

## 🛠️ 使用方式

### 1. 硬體需求

- ESP32 開發板  
- LED x1（建議加 220Ω 限流電阻）  
- 麵包板與跳線  

### 2. 軟體安裝

#### 📲 ESP32 韌體

將 `esp32-led-control.ino` 上傳至 ESP32，並修改以下設定：

```cpp
const char* ssid = "你的WiFi名稱";
const char* password = "你的WiFi密碼";
const int ledPin = 2; // 根據你的接腳修改
```

🌐 **開啟前端網頁（HTML）**  
打開 `index.html`，輸入 ESP32 的 IP（如 `http://192.168.4.1`），即可控制燈光：

- 啟用語音控制（支援中文指令）
- 使用滑桿調整亮度

🎙️ **語音控制指令範例**  

| 語音指令     | 功能            |
|--------------|----------------|
| 開燈         | 開啟 LED       |
| 關燈         | 關閉 LED       |
| 最亮         | 亮度設為 255   |
| 超級暗       | 亮度設為 10    |
| 中等         | 亮度設為 128   |
| 亮度 128     | 自訂亮度       |
| 亮一點 / 暗一點 | 增減 25 亮度 |

---

## 🧠 技術說明

- **語音辨識**：Web Speech API（支援中文）  
- **前端網頁架構**：HTML + JavaScript  
- **ESP32 韌體控制**：WiFi + WebServer + PWM  
- **通訊方式**：HTTP GET 傳送指令  

---

## 🔮 未來展望

- 多燈控制與場景模式（如閱讀、夜燈等）  
- 專屬手機 App（WiFi 或藍牙控制）  
- 加入語音密碼與語者辨識強化安全性  
- 支援語音自訂學習、自然語言解析  
- 整合 Google Home / Home Assistant 智慧家庭平台  

---

## 📚 參考資料

- [語音控制 LED 教學影片](https://www.youtube.com/watch?v=boKeP0Bc5wo)  
- [Medium - Arduino × Teachable Machine × p5.js](https://alankrantas.medium.com/%E7%B5%A6-arduino-%E5%A4%96%E6%8E%9B%E4%B8%80%E9%A1%86-ai-%E8%85%A6-%E4%BD%BF%E7%94%A8%E9%9B%A2%E7%B7%9A%E7%89%88-teachable-machine-%E5%92%8C-javascript-p5-js-87a4b312caed)
- [Teachable Machine 語音訓練平台](https://teachablemachine.withgoogle.com/train/audio) 
- [PWM 原理圖示](https://content.instructables.com/FVG/27FE/L8X2KZYK/FVG27FEL8X2KZYK.png)  

---
