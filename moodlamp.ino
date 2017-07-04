#define DELAY_TIME 20   // Задержка на смену цвета
#define MAX_BRIGHT 255  // Максимальная яркость
 
// Пины на выходные цвета. Должны быть PWM
#define PIN_RED 9
#define PIN_GREEN 10
#define PIN_BLUE 11
 
// Начальные значения для цветов
int red = 0;
int green = 170;
int blue = 170;
 
// Увеличивается или уменьшается ли цвет
int incR = 1;
int incG = 1;
int incB = 0;
 
// Чёрная магия
void transition()
{
  if (red >= MAX_BRIGHT)
    incR = 0;
  else if (red <= 0)
    incR = 1;
  if (green >= MAX_BRIGHT)
    incG = 0;
  else if (green <= 0)
    incG = 1;
  if (blue >= MAX_BRIGHT)
    incB = 0;
  else if (blue <= 0)
    incB = 1;
 
  if (incR)
    red++;
  else
    red--;
  if(incG)
    green++;
  else
    green--;
  if(incB)
    blue++;
  else
    blue--;
}

// Функция для вывода значения переменных на физические пины
void setColor()
{
  analogWrite(PIN_RED, red);
  analogWrite(PIN_GREEN, green);
  analogWrite(PIN_BLUE, blue);
}
 
void setup()
{
  // Смотрим аниме.
}
 
void loop()
{
  transition();
  setColor();
  delay(DELAY_TIME);
}
