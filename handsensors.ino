#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inicializa la pantalla LCD con la dirección I2C 0x27
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Clase para manejar la pantalla LCD
class PantallaLCD {
  public:
    void inicializar() {
      lcd.init();  // Inicializa la pantalla LCD
      lcd.backlight();  // Activa la luz de fondo de la LCD
    }

    void mostrarMensaje(const char* mensaje) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(mensaje);
      delay(3000); // Espera 3 segundos antes de borrar el mensaje
    }

    void limpiarPantalla() {
      lcd.clear();
    }
};

// Definición de la clase SensorFlex
class SensorFlex {
  public:
    int pin; 
    int resistencia;
    int curvatura;

    SensorFlex(int p) : pin(p) {}

    int leerValor() {
      resistencia = analogRead(pin); 
      curvatura = map(resistencia, 0, 1023, 0, 100); 
      return curvatura;
    }
};

// Clase para gestionar el guante
class GuanteSensorizado {
  public:
    SensorFlex pulgar;
    SensorFlex indice;
    SensorFlex corazon;
    SensorFlex anular;
    SensorFlex menique;
    PantallaLCD pantalla;  // Asocia la pantalla con el guante

    GuanteSensorizado(int pinPulgar, int pinIndice, int pinCorazon, int pinAnular, int pinMenique) :
      pulgar(pinPulgar), indice(pinIndice), corazon(pinCorazon), anular(pinAnular), menique(pinMenique) {}

    void inicializar() {
      pantalla.inicializar();  // Inicializa la pantalla
      Serial.begin(9600);  // Inicializa la comunicación serial
    }

    void leerSensores() {
      int curvaturaPulgar = pulgar.leerValor();
      int curvaturaIndice = indice.leerValor();
      int curvaturaCorazon = corazon.leerValor();
      int curvaturaAnular = anular.leerValor();
      int curvaturaMenique = menique.leerValor();

      // Muestra los valores en el monitor serial
      Serial.println("Valores de curvatura:");
      Serial.print("Pulgar: ");
      Serial.println(curvaturaPulgar);
      Serial.print("Indice: ");
      Serial.println(curvaturaIndice);
      Serial.print("Corazon: ");
      Serial.println(curvaturaCorazon);
      Serial.print("Anular: ");
      Serial.println(curvaturaAnular);
      Serial.print("Menique: ");
      Serial.println(curvaturaMenique);

      // Verifica las condiciones de los dedos y muestra el mensaje correspondiente
      if (curvaturaIndice >= 80 && curvaturaIndice <= 90) {
        pantalla.mostrarMensaje("Tengo hambre");
      }
      else if (curvaturaCorazon >= 80 && curvaturaCorazon <= 90) {
        pantalla.mostrarMensaje("Tengo sed");
      }
      else if (curvaturaAnular >= 88 && curvaturaAnular <= 90 && curvaturaMenique >= 78 && curvaturaMenique <= 90) {
        pantalla.mostrarMensaje("Ir al banio");
      }
      else if (curvaturaAnular >= 87 && curvaturaAnular <= 90) {
        pantalla.mostrarMensaje("Estoy bien");
      }
      else if (curvaturaPulgar >= 10 && curvaturaPulgar <= 30) {
        pantalla.mostrarMensaje("Tengo dolor");
      }
      else {
        pantalla.limpiarPantalla();  // Limpia la pantalla si no hay coincidencias
      }
    }
};

// Creación de una instancia del guante sensorizado
GuanteSensorizado guante(A0, A1, A2, A3, A4);

void setup() {
  guante.inicializar();  // Inicializa los componentes del guante
}

void loop() {
  guante.leerSensores();  // Lee los valores de los sensores y muestra el mensaje correspondiente
  delay(1000);  // Espera antes de la siguiente lectura
}
