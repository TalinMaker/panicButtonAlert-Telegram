# Panic Button with ESP32

## Overview

This project implements a panic button using an ESP32 microcontroller, an LED, a passive buzzer, and the Telegram API to send an alert message when the button is pressed. When the panic button is activated, the system will:
1. Trigger an LED to indicate an alert.
2. Sound the buzzer to signal an emergency.
3. Send a message via Telegram to notify the user of the panic button being pressed.

## Components

- **ESP32**
- **Push Button**
- **LED (any color)**
- **Passive Buzzer**
- **Resistors (for button and LED)**
- **Jumper wires**
- **Breadboard** (optional, for prototyping)

## Circuit Diagram

The circuit is simple:
1. Connect one side of the button to **GPIO 12** (configured as an input).
2. Connect the other side of the button to **GND**.
3. Connect the **LED** to **GPIO 13** with a current-limiting resistor (typically 220 ohms).
4. Connect the **buzzer** to **GPIO 26**.

## Telegram Setup

1. Create a new bot in Telegram by chatting with [BotFather](https://core.telegram.org/bots#botfather).
2. Get your **Bot Token** from BotFather.
3. Find your **Chat ID** by messaging your bot and using the [Telegram API](https://api.telegram.org/bot<YourBotToken>/getUpdates) to retrieve it.
4. Replace `YOUR_BOT_TOKEN` and `YOUR_CHAT_ID` in the code with your actual bot token and chat ID.

## Code