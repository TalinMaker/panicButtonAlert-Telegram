#include <WiFi.h>
#include <HTTPClient.h>

// Define Wi-Fi credentials
const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

// Define your Telegram bot token
String botToken = "YOUR_BOT_TOKEN";
String chatID = "YOUR_CHAT_ID";

// Define pins
const int buttonPin = 12;    // Pin where the button is connected
const int buzzerPin = 26;     // Pin for the buzzer
const int ledPin = 13;        // Pin for the LED

// Variable to store the button state
int buttonState = 0;

void setup() {
  // Configure pins
  pinMode(buttonPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  
  // Connect to Wi-Fi
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to Wi-Fi...");
  }
  Serial.println("Connected to Wi-Fi!");
}

void loop() {
  // Check if the button was pressed
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    // Send a message on Telegram
    sendMessage("Panic button pressed.");

    // Activate the siren and the LED
    digitalWrite(buzzerPin, HIGH); // Turn on the buzzer
    digitalWrite(ledPin, HIGH);    // Turn on the LED
    delay(10000);                   // Keep them on for 1 second

    // Turn off the siren and the LED
    digitalWrite(buzzerPin, LOW);  // Turn off the buzzer
    digitalWrite(ledPin, LOW);     // Turn off the LED
  }

  delay(100); // Prevent rapid button reading
}

// Function to send a message on Telegram
void sendMessage(String message) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String url = "https://api.telegram.org/bot" + botToken + "/sendMessage?chat_id=" + chatID + "&text=" + message;
    
    http.begin(url);
    int httpResponseCode = http.GET();

    if (httpResponseCode > 0) {
      Serial.println("Message sent successfully.");
    } else {
      Serial.print("Error sending message: ");
      Serial.println(httpResponseCode);
    }
    
    http.end();
  } else {
    Serial.println("Not connected to Wi-Fi");
  }
}
