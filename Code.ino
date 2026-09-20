#include <TFT_eSPI.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <ArduinoJson.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <DHT.h>
#include <WiFiClientSecure.h>



#define TYPE DHT11
#define DHTPIN 27


const char* ssid = "YOUR_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

DHT dht = DHT(27, DHT11);

// Declare Global Variables

unsigned long consultatemp = 0;
const unsigned long intervaltemp = 600000;
unsigned long consultahora = 0;
const unsigned long intervalhora = 1000;
String horacompleta = ".";
String horadisplay = "--:--";
String dia = "";
float tempnum = 0.0;
float tempint = 0.0;
int humint = 0;
float tempdema = 0.0;
String tempdescr = "";
const int pinBoto = 22;
int canvi = 99;
int demaplou = 0;
int demahum = 0;
String demallun = "";
String demadef = "";
float dostemp = 0.0;
int dosplou = 0;
float trestemp = 0.0;
int tresplou = 0;
int avuiplou = 0;
float velocitataire = 0.0;
String sentitaire = "";
int humitat = 0;
float sensaciotermica = 0.0;
String alerta = "There are no alerts.";
String quotedisplay = "";
String author = "";
int pantalla = 0;
int initialize = 0;
String totaltimelast7days = "";
String editormesusat = "";
String llenguatgemesusat = "";
String projectemestreballat = "";
int newnum = 50;


// Declare API links

String weatherapi = "WEATHERAPI_URL";
String timeapi = "TIMEAPI_URL";
String jokeapi = "https://icanhazdadjoke.com";
String quoteapi = "https://zenquotes.io/api/random";
String hackapi = "HACKATIME_URL";







TFT_eSPI tft = TFT_eSPI();

void setup() {

  Serial.begin(115200);
  pinMode(21, OUTPUT);
  digitalWrite(21, HIGH);
  tft.init();
  tft.setRotation(1);
  dht.begin();

  pinMode(pinBoto, INPUT_PULLUP);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    tft.print(".");
  }

  extraerTemp();
  extraerHora();
  consultatemp = millis();
  consultahora = millis();

  pantalla = 0;
}

void extraerTemp() {
  JsonDocument climafilter;
  JsonDocument clima;
  HTTPClient http;
  http.begin(weatherapi);
  http.GET();
  String climainfo = http.getString();
  climafilter["current"]["temp_c"] = true;
  climafilter["current"]["condition"]["text"] = true;
  climafilter["current"]["chance_of_rain"] = true;
  climafilter["forecast"]["forecastday"] = true;
  climafilter["current"]["wind_kph"] = true;
  climafilter["current"]["wind_dir"] = true;
  climafilter["current"]["humidity"] = true;
  climafilter["current"]["feelslike_c"] = true;
  deserializeJson(clima, climainfo, DeserializationOption::Filter(climafilter));
  clima.shrinkToFit();

  tempnum = clima["current"]["temp_c"];
  tempdescr = clima["current"]["condition"]["text"].as<String>();
  tempdema = clima["forecast"]["forecastday"][1]["day"]["avgtemp_c"];
  avuiplou = clima["current"]["chance_of_rain"];
  demaplou = clima["forecast"]["forecastday"][1]["day"]["daily_chance_of_rain"];
  demahum = clima["forecast"]["forecastday"][1]["day"]["avghumidity"];
  demallun = clima["forecast"]["forecastday"][1]["astro"]["moon_phase"].as<String>();
  demadef = clima["forecast"]["forecastday"][1]["day"]["condition"]["text"].as<String>();
  dostemp = clima["forecast"]["forecastday"][2]["day"]["avgtemp_c"];
  dosplou = clima["forecast"]["forecastday"][2]["day"]["daily_chance_of_rain"];
  velocitataire = clima["current"]["wind_kph"];
  sentitaire = clima["current"]["wind_dir"].as<String>();
  humitat = clima["current"]["humidity"];
  sensaciotermica = clima["current"]["feelslike_c"];
  http.end();
}

void extraerHora() {
  JsonDocument hora;
  HTTPClient http;
  http.begin(timeapi);
  http.GET();
  String horainfo = http.getString();
  deserializeJson(hora, horainfo);
  horacompleta = String(hora["time"]);
  horadisplay = horacompleta.substring(0, 5);
  dia = hora["day_of_week"].as<String>();
  http.end();
}

void extraerJoke() {
  JsonDocument joke;
  HTTPClient http;
  http.begin(jokeapi);
  http.addHeader("Accept", "application/json");
  http.GET();
  String jokecontent = http.getString();
  deserializeJson(joke, jokecontent);
  joketext = String(joke["joke"]);
  http.end();
}

void extraerQuote() {
  JsonDocument quote;
  HTTPClient http;
  http.begin(quoteapi);
  http.GET();
  String quotecontent = http.getString();
  deserializeJson(quote, quotecontent);
  quotedisplay = String(quote[0]["q"]);
  author = String(quote[0]["a"]);
  http.end();
}

void extraerTime() {
  JsonDocument hackatimefilter;
  JsonDocument hackatime;
  HTTPClient http;
  http.begin(hackapi);
  http.GET();
  String timecontent = http.getString();
  hackatimefilter["data"]["human_readable_total"] = true;
  hackatimefilter["data"]["editors"] = true;
  hackatimefilter["data"]["languages"] = true;
  hackatimefilter["data"]["projects"] = true;
  deserializeJson(hackatime, timecontent, DeserializationOption::Filter(hackatimefilter));
  hackatime.shrinkToFit();
  totaltimelast7days = hackatime["data"]["human_readable_total"].as<String>();
  editormesusat = hackatime["data"]["editors"][0]["name"].as<String>();
  llenguatgemesusat = hackatime["data"]["languages"][0]["name"].as<String>();
  projectemestreballat = hackatime["data"]["projects"][0]["name"].as<String>();
  http.end();
}

void caretes() {
  // Lopaka generated:
  if (tempnum >= 30) {
    tft.fillRect(203, 129, 85, 86, 0xE0C4);
    // ellipse 2
    tft.fillEllipse(225, 153, 7, 7, 0x0);
    // ellipse 3
    tft.fillEllipse(266, 153, 7, 7, 0x0);
    // rect 4
    tft.fillRect(222, 191, 48, 11, 0x0);
    // rect 5
    tft.fillRect(239, 198, 13, 14, 0xD38E);
    // line 6
    tft.drawLine(245, 199, 246, 208, 0x0);
    // ellipse 7
    tft.fillEllipse(279, 179, 5, 5, 0x9E1E);
    // triangle 8
    tft.fillTriangle(278.5, 167, 283, 177, 274, 177, 0x9E1E);
  }

  if (tempnum < 30 && tempnum > 23) {

    tft.fillRect(203, 128, 85, 86, 0xFBC0);
    // ellipse 2
    tft.fillEllipse(225, 153, 7, 7, 0x0);
    // ellipse 3
    tft.fillEllipse(266, 153, 7, 7, 0x0);
    // rect 4
    tft.fillRect(222, 191, 48, 11, 0x0);
    // ellipse 7
    tft.fillEllipse(279, 179, 5, 5, 0x9E1E);
    // triangle 8
    tft.fillTriangle(278.5, 167, 283, 177, 274, 177, 0x9E1E);
  }

  if (tempnum < 23 && tempnum > 19) {
    tft.fillRect(203, 128, 85, 86, 0x8E09);
    // ellipse 2
    tft.fillEllipse(225, 153, 7, 7, 0x0);
    // ellipse 3
    tft.fillEllipse(266, 153, 7, 7, 0x0);
    // ellipse 4
    tft.fillEllipse(245, 188, 19, 13, 0x0);
    // rect 5
    tft.fillRect(209, 171, 70, 18, 0x8E09);
  }

  if (tempnum < 19 && tempnum > 10) {
    tft.fillRect(203, 128, 85, 86, 0x343C);
    // ellipse 2
    tft.fillEllipse(225, 153, 7, 7, 0x0);
    // ellipse 3
    tft.fillEllipse(266, 153, 7, 7, 0x0);
    // rect 4
    tft.fillRect(222, 191, 48, 11, 0x0);
  }

  if (tempnum < 10) {
    tft.fillRect(203, 128, 85, 86, 0x9215);
    // ellipse 2
    tft.fillEllipse(225, 153, 7, 7, 0x0);
    // ellipse 3
    tft.fillEllipse(266, 153, 7, 7, 0x0);
    // ellipse 4
    tft.fillEllipse(246, 192, 22, 10, 0x0);
    // rect 5
    tft.fillRect(214, 193, 61, 14, 0x9215);
    // ellipse 6
    tft.fillEllipse(251, 171, 0, 4, 0x9215);
    // rect 7
    tft.fillRect(191, 201, 108, 19, 0xE0C4);
    // triangle 8
    tft.fillTriangle(207.5, 201, 217, 219, 198, 219, 0xFFFF);
    // triangle 9
    tft.fillTriangle(251.5, 202, 265, 219, 238, 219, 0xFFFF);
    // triangle 10
    tft.fillTriangle(291.5, 203, 298, 218, 285, 218, 0xFFFF);
  }
  // End Lopaka generated
}

void pantallainicial() {
  if (initialize == 0) {
    extraerTemp();
    extraerHora();
    extraerQuote();
    initialize = 1;
  }

  if (canvi != 0) {
    tft.fillScreen(TFT_BLACK);
    caretes();
  }

  if (millis() - consultatemp >= intervaltemp) {
    consultatemp = millis();
    extraerTemp();
  }

  if (millis() - consultahora >= intervalhora) {
    consultahora = millis();
    extraerHora();
  }

  tempint = dht.readTemperature();
  humint = dht.readHumidity();
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(6);
  tft.drawString(horadisplay, 8, 15);

  tft.setTextSize(4);
  tft.drawString(String(tempnum, 1) + " C", 12, 130);

  tft.setTextSize(3);
  tft.drawString(dia, 12, 196);
  tft.drawString("Temperature", 10, 75);

  tft.setTextSize(2);
  tft.drawString("Rain prob.:", 200, 20);
  tft.drawString(String(avuiplou) + "%", 245, 45);
  tft.drawString("Exterior", 12, 105);

  tft.setTextSize(1);
  tft.drawString("`" + tempdescr + "'", 25, 169);


  delay(200);
}

void climadetall() {
  if (canvi != 1) {
    tft.fillScreen(TFT_BLACK);
  }

  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(3);
  tft.drawString("Current weather", 28, 10);
  tft.setTextSize(2);
  tft.drawString("Temperature: " + String(tempnum, 1) + " C", 10, 50);
  tft.drawString("Interior temp.: " + String(tempint, 1) + " C", 10, 75);
  tft.drawString("Feels like: " + String(sensaciotermica, 1) + " C", 10, 100);
  tft.drawString("Humidity: " + String(humitat) + " %", 10, 125);
  tft.drawString("Air speed: " + String(velocitataire, 1) + " km/h", 10, 150);
  tft.drawString("Air direction: " + String(sentitaire), 10, 175);
}

void forecast() {

  if (canvi != 2) {
    tft.fillScreen(TFT_BLACK);
  }
  tft.drawRect(5, 56, 147, 160, TFT_RED);
  tft.drawRect(158, 56, 160, 80, TFT_BLUE);
  tft.drawRect(158, 140, 160, 76, TFT_YELLOW);

  tft.setTextSize(4);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.drawString("Forecast", 65, 12);

  tft.setTextSize(2);
  tft.drawString("Tomorrow", 12, 65);
  tft.drawString(String(tempdema, 1) + " C", 48, 95);
  tft.drawString(String(demaplou) + "%", 80, 120);
  tft.drawString(String(demahum) + "%", 67, 145);
  tft.drawString("In 2 days", 183, 60);
  tft.drawString(String(dostemp, 1) + " C", 220, 87);
  tft.drawString(String(dosplou) + "%", 251, 113);
  tft.drawString("Now (Int.)", 183, 145);
  tft.drawString(String(tempint, 1) + " C", 220, 172);
  tft.drawString(String(humint) + "%", 240, 193);

  tft.setTextSize(1);
  tft.drawString("Temp.", 12, 100);
  tft.drawString("Rain prob.", 12, 125);
  tft.drawString("Humidity", 12, 150);
  tft.drawString("'" + demallun + "'", 12, 177);
  tft.drawString("'" + demadef + "'", 12, 198);
  tft.drawString("Temp.", 183, 92);
  tft.drawString("Rain prob.", 183, 117);
  tft.drawString("Temp.", 183, 177);
  tft.drawString("Humidity", 183, 198);
  tft.drawString("Enjoy the present, control the future.", 50, 224);
}

void jokeScreen() {
  if (canvi != 3) {
    tft.fillScreen(TFT_BLACK);
    tft.fillRect(-10, 80, 380, 60, TFT_YELLOW);
    extraerJoke();

    // [BEGIN lopaka generated]
    tft.fillEllipse(164, 194, 39, 39, 0xFE00);
    tft.fillEllipse(164, 211, 27, 11, 0x0);
    tft.fillEllipse(164, 212, 25, 8, 0xFFFF);
    tft.fillRect(129, 198, 67, 16, 0xFE00);
    tft.fillEllipse(136, 202, 7, 5, 0x9E1E);
    tft.fillEllipse(190, 201, 8, 5, 0x9E1E);
    tft.fillTriangle(135.5, 188, 130, 200, 141, 200, 0x9E1E);
    tft.fillEllipse(144, 179, 6, 7, 0x0);
    tft.fillTriangle(190, 186, 196, 199, 184, 199, 0x9E1E);
    tft.fillEllipse(185, 178, 6, 7, 0x0);
    tft.fillRect(132, 180, 60, 7, 0xFE00);
    // [END lopaka generated]

    tft.setTextColor(TFT_WHITE);
    tft.setTextSize(4);
    tft.drawString("JOKES!", 88, 10);
  }

  tft.setTextColor(TFT_BLACK);
  tft.setTextSize(1);
  tft.setTextWrap(true, true);
  tft.setCursor(10, 90);
  tft.print(joketext);
}


void quotescreen() {
  if (canvi != 4) {
    tft.fillScreen(TFT_BLACK);
    tft.setTextSize(3);
    tft.setTextColor(TFT_WHITE);
    tft.drawString("Quote", 130, 5);
  }

  tft.setTextWrap(true, true);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(1);
  tft.setCursor(5, 50);
  tft.print("'" + quotedisplay + "'");
  tft.setCursor(200, 120);
  tft.println("'" + author + "'");
  tft.setCursor(220, 230);
  tft.print("zenquotes.io");
}

void hackatimedraw() {
  if (canvi != 5) {
    tft.fillScreen(TFT_BLACK);
    extraerTime();
    canvi = 5;
  }
  tft.setTextSize(2);
  tft.setTextColor(TFT_WHITE);
  tft.drawString("Last 7 days coding", 50, 5);
  tft.drawString("Total time: " + totaltimelast7days, 5, 50);
  tft.drawString(llenguatgemesusat, 125, 95);
  tft.drawString(projectemestreballat, 155, 145);

  tft.setTextSize(1);
  tft.drawString("Most used language:", 5, 100);
  tft.drawString("Most worked on project: ", 5, 150);
  tft.setTextColor(TFT_GREEN);
  tft.drawString("01001101 01000010 01010010 00110010 00110011", 2, 230);
}

void loop() {


  if (digitalRead(pinBoto) == LOW) {
    pantalla = pantalla + 1;
    delay(150);
  }

  if (pantalla == 0 || pantalla > 6 ) {
    pantallainicial();
    canvi = 0;
  }

  else if (pantalla == 1) {
    climadetall();
    canvi = 1;
  }

  else if (pantalla == 2) {
    forecast();
    canvi = 2;
  }

  else if (pantalla == 3) {
    jokeScreen();
    canvi = 3;
  }


  else if (pantalla == 4) {
    quotescreen();
    canvi = 4;
  }

  else if (pantalla == 5) {
    hackatimedraw();
    canvi = 5;
  }

  if (pantalla >= 6) {
    pantalla = 0;
  }

  delay(20);
}
