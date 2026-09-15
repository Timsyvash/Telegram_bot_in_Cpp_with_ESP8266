# ESP8266 Telegram Servo Controller

Проєкт для дистанційного керування серводвигуном та отримання сповіщень через **Telegram Bot** на базі плати **WeMos D1 Mini (ESP8266)**, розроблений у середовищі **PlatformIO (C++)**.

---

## 🛠 Технології та Бібліотеки

* **Платформа:** ESP8266 (WeMos D1 Mini)
* **Фреймворк:** Arduino Framework (PlatformIO)
* **Мова:** C++
* **Основні бібліотеки:**
  * `ESP8266WiFi` / `WiFiClientSecure` — створення захищеного SSL-з'єднання з мережею Інтернет.
  * `UniversalTelegramBot` (v1.3.0) — робота з Telegram Bot API.
  * `ArduinoJson` (v6.21.5) — парсинг JSON-відповідей від Telegram.
  * `Servo` — керування серводвигуном через шім-сигнал (вбудована в ESP8266 Core).

---

## 📋 Схема підключення (Pinout)

| Компонент | Пін на серво | Пін на WeMos D1 Mini | GPIO |
| :--- | :--- | :--- | :--- |
| **Servo Motor** | Signal (Жовтий/Оранжевий) | `D3` | `GPIO 0` |
| **Servo Motor** | VCC (Червоний) | `5V` / `3.3V` | — |
| **Servo Motor** | GND (Коричневий/Чорний) | `GND` | — |

---

## ⚡ Команди Telegram Бота

Після запуску пристрою та підключення до Wi-Fi, бот підтримує наступні команди в чаті:

* `/s45` — встановити кут повороту серводвигуна на **45°**.
* `/s90` — встановити кут повороту серводвигуна на **90°**.
* `/s125` — встановити кут повороту серводвигуна на **125°**.
* `/help` — отримати список доступних команд.

---

## 🚀 Налаштування та Запуск

### 1. Клонування репозиторію
```bash
git clone [https://github.com/your-username/Telegram_bot_in_Cpp_with_ESP8266.git](https://github.com/your-username/Telegram_bot_in_Cpp_with_ESP8266.git)
cd Telegram_bot_in_Cpp_with_ESP8266
