#define motor_l1 2
#define motor_l2 3
#define motor_r1 4
#define motor_r2 5
#define channel3 6
#define channel1 7

int bacachannel(int channelInput, int minLimit, int maxLimit, int defaultValue)
{
  int ch = pulseIn(channelInput, HIGH, 30000);
  if (ch < 100) return defaultValue;
  return map(ch, 1000, 2000, minLimit, maxLimit);
}

void input_rl(int kanankiri)
{
  if(kanankiri<-50)
  {
    digitalWrite(motor_l1, HIGH);
    digitalWrite(motor_l2, LOW);
    digitalWrite(motor_r1, LOW);
    digitalWrite(motor_r2, HIGH);
  }
  else if (kanankiri>50)
  {
    digitalWrite(motor_l1, LOW);
    digitalWrite(motor_l2, HIGH);
    digitalWrite(motor_r1, HIGH);
    digitalWrite(motor_r2, LOW);
  }
}

void input_fb(int majumundur)
{
  if(majumundur<-50)
  {
    digitalWrite(motor_l1, HIGH);
    digitalWrite(motor_l2, LOW);
    digitalWrite(motor_r1, HIGH);
    digitalWrite(motor_r2, LOW);
  }
  else if (majumundur>50)
  {
    digitalWrite(motor_l1, LOW);
    digitalWrite(motor_l2, HIGH);
    digitalWrite(motor_r1, LOW);
    digitalWrite(motor_r2, HIGH);
  }
  else
  {
    digitalWrite(motor_l1, LOW);
    digitalWrite(motor_l2, LOW);
    digitalWrite(motor_r1, LOW);
    digitalWrite(motor_r2, LOW);
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(motor_l1, OUTPUT);
  pinMode(motor_l2, OUTPUT);
  pinMode(motor_r1, OUTPUT);
  pinMode(motor_r2, OUTPUT);
  pinMode(channel3, INPUT);
  pinMode(channel1, INPUT);
}

void loop() {
  int majumundur = bacachannel(channel3, -100, 100, 0);
  int kanankiri = bacachannel(channel1, -100, 100, 0);
  if(kanankiri<50 && kanankiri>-50)
  {
    input_fb(majumundur);
  }
  else
  {
    input_rl(kanankiri);
  }
}
