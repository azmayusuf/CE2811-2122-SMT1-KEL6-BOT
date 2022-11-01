#include "CTBot.h"
CTBot myBot;

String ssid = "Dosen ITEBA2";     // Sesuikan dengan nama wifi anda
String pass = "itebabatam"; // sesuaikan password wifi
String token = "5711320281:AAHE8SX-k9iyjo7KgM5U038XwLlhmTYFzNs"; // token bot telegram yang telah dibuat

String data;
char c;

void setup() {
	Serial.begin(115200);
	Serial.println("Memulai Telegram Bot...");
  
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledState);
  

	myBot.wifiConnect(ssid, pass);

	myBot.setTelegramToken(token);

	// check if all things are ok
	if (myBot.testConnection())
		Serial.println("\ntestConnection OK");
	else
		Serial.println("\ntestConnection NOK");

}

void loop() {
	TBMessage msg;

	if (myBot.getNewMessage(msg)) {

		if (msg.text.equalsIgnoreCase("LAMPU ON")) {              
			myBot.sendMessage(msg.sender.id, "LAMPU SEDANG MENYALA");  //kirim pesan ke bot telegram
		  Serial.print("LAMPU ON");
      ledState = HIGH;
      digitalWrite(ledPin, ledState);
		}
		else if (msg.text.equalsIgnoreCase("LAMPU OFF")) {        
			myBot.sendMessage(msg.sender.id, "LAMPU SEDANG MATI"); 
		  Serial.print("LAMPU OFF");
      ledState = LOW;
      digitalWrite(ledPin, ledState);
		}
    else if (msg.text.equalsIgnoreCase("TEMPERATURE")) {
      Serial.print("TEMPERATURE");
    }
		else {                                                    
			// membalas pesan selain kode diatas
			String reply;
			reply = (String)"Selamat datang " + msg.sender.firstName + (String)". Ketik Perintah : LAMPU ON, LAMPU OFF";
			myBot.sendMessage(msg.sender.id, reply);         
		}
	}
  
  while(Serial.available()>0){
    delay(10);
    c = Serial.read();
    data += c;
  }

	delay(500);
}
