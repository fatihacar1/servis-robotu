#include <SoftwareSerial.h>

// L298N Motor Sürücü Pinleri
#define ENA 10
#define IN1 9
#define IN2 8
#define ENB 5
#define IN3 7
#define IN4 6

char command; // Python'dan gelen komut

void setup() {
    Serial.begin(9600); // Seri haberleşmeyi başlat
    pinMode(ENA, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);

    stopMotors(); // Başlangıçta motorları durdur
}

void loop() {
    if (Serial.available() > 0) { // Eğer Python'dan veri geldiyse
        command = Serial.read();  // Veriyi oku

        if (command == '1') { // Şerit tespit edildi
            moveForward();  // Motorları ileri hareket ettir
        } 
        else if (command == '0') { // Şerit kayboldu veya dur komutu
            stopMotors();  // Motorları durdur
        }
    }
}

// **Motorları ileri hareket ettir**
void moveForward() {
    analogWrite(ENA, 140); // Motor hızını belirle (0-255 arası)
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    analogWrite(ENB, 140);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

// **Motorları durdur**
void stopMotors() {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}
