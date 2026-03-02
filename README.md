# 🌬️ Smart HVAC Airflow Balancing System

> An IoT-based intelligent airflow control system that automatically adjusts fan speed based on real-time temperature conditions using a **DHT11** sensor, **ESP8266** microcontroller, and **PWM control** via an **L298N motor driver**.

---

## 📌 Project Overview

Traditional HVAC systems often distribute air at a constant rate without considering temperature changes in the environment. This project introduces a **smart airflow balancing system** that monitors temperature and automatically controls fan speed to maintain comfortable conditions and improve energy efficiency.

The system continuously reads temperature data and adjusts the cooling fan speed accordingly.

---

## ✨ Features

- 🌡️ Real-time temperature monitoring
- ⚡ Automatic fan speed control
- 🔧 PWM-based airflow regulation
- 💡 Energy-efficient cooling
- 🛠️ Simple and low-cost hardware setup
- 🌐 Expandable for IoT monitoring

---

## 🧰 Hardware Components

| Component | Description |
|---|---|
| ESP8266 NodeMCU | Main microcontroller |
| DHT11 Temperature Sensor | Reads ambient temperature |
| L298N Motor Driver Module | Controls fan speed via PWM |
| 5V DC Fan | Cooling output |
| External 5V Power Supply | Powers the motor driver |
| Jumper Wires | Connections |
| Breadboard | Prototyping base |

---

## 🏗️ System Architecture

```
Temperature Sensor → ESP8266 Controller → PWM Signal → L298N Driver → Cooling Fan
```

The **DHT11** sensor collects temperature data and sends it to the **ESP8266**. The microcontroller processes the data and generates a **PWM signal** that controls the fan speed through the **L298N motor driver**.

---

## 🔌 Circuit Connections

### NodeMCU → L298N

| NodeMCU | L298N |
|---------|-------|
| D1 | ENA |
| D2 | IN1 |
| D3 | IN2 |
| GND | GND |

### Fan → L298N

| Fan | L298N |
|-----|-------|
| + | OUT1 |
| - | OUT2 |

### DHT11 → NodeMCU

| DHT11 | NodeMCU |
|-------|---------|
| VCC | 3.3V |
| GND | GND |
| DATA | D5 |

### ⚡ Power Setup

- ESP8266 powered through **USB**
- L298N powered via **external 5V supply**
- ⚠️ **Ground must be common** between ESP8266 and L298N

---

## 💻 Software Requirements

- [Arduino IDE](https://www.arduino.cc/en/software)
- ESP8266 Board Package
- DHT Sensor Library

---

## 🚀 Installation

1. Install **Arduino IDE**
2. Install **ESP8266 board support** in Board Manager
3. Install the **DHT sensor library**
4. Connect hardware according to the diagram above
5. Upload the code to the ESP8266

---

## ⚙️ How It Works

1. The **DHT11 sensor** reads temperature from the environment
2. **ESP8266** processes the sensor data
3. Based on temperature, a **PWM signal** is generated
4. **L298N** adjusts the fan speed accordingly
5. Fan speed **increases as temperature rises**

---

## Example Output

| Temperature | Fan Speed |
|-------------|-----------|
| 24°C | 🟢 Low |
| 27°C | 🟡 Medium |
| 31°C | 🔴 High |

---

## Applications

- 🏠 Smart home ventilation
- 🚗 Vehicle cabin cooling systems
- 🖥️ Server room temperature control
- 🚛 Refrigerated transport monitoring
- 🏢 Energy-efficient HVAC systems

---

## 🔮 Future Improvements

- [ ] Multi-zone airflow balancing
- [ ] Cloud monitoring using IoT platforms
- [ ] Mobile app control
- [ ] Machine learning based temperature prediction
- [ ] Integration with smart building systems

---

## 📄 License

This project is open-source and available under the [MIT License](LICENSE).
