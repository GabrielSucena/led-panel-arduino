int BT_1 = 5;
int BT_2 = 6;

int cont = 0;

int uni;
int dec;
int cen;

void setup()
{
  pinMode(BT_1, INPUT_PULLUP);
  pinMode(BT_2, INPUT_PULLUP);
  
  DDRB = B111111;
  DDRC = B111111;
  DDRD = B00011111;
  
}
void loop (){
  
  uni = cont % 10; 
  dec = (cont/10)%10; 
  cen = (cont/100)%10; 
  
  PORTC = uni;
  PORTB = dec;
  PORTD = (1<<PD7) | (1<<PD6) | (1<<PD5) | cen;
  
  if (digitalRead(BT_1) == 0){
    cont++;
    delay(500);
  }
  
  if (digitalRead(BT_2) == 0){
    cont--;
    delay(500);
  }
}
