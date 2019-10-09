

#include <Stepper.h>
const int stepsPerRevolution = 200;
#define RIGHT_STEP_CW 50
Stepper FStepper(stepsPerRevolution, 8, 9, 10, 11);
Stepper BStepper(stepsPerRevolution, 6, 5, 4, 3);
Stepper UStepper(stepsPerRevolution, 22, 23, 26, 25);
Stepper DStepper(stepsPerRevolution, 30, 31, 32, 33);
Stepper RStepper(stepsPerRevolution, 38, 39, 40, 41);
Stepper LStepper(stepsPerRevolution, 46, 47, 48, 49);


int nOFm = 0;
char yellow_side[9] = {'y', 'y', 'y', 
                       'y', 'y', 'y',
                       'y', 'y', 'y'
                      };

char white_side[9] =  {'w', 'w', 'w',
                       'w', 'w', 'w',
                       'w', 'w', 'w'
                      };
char blue_side[9] =   {'b', 'g', 'o',
                       'b', 'b', 'b',
                       'b', 'b', 'b'
                      };

char red_side[9] =    {'o', 'r', 'r',
                       'r', 'r', 'r',
                       'r', 'r', 'r'
                      };

char green_side[9] =  {'r', 'o', 'b',
                       'g', 'g', 'g',
                       'g', 'g', 'g'
                      };

char orange_side[9] =  {'g', 'b', 'g',
                       'o', 'o', 'o',
                       'o', 'o', 'o'
                      };

// prints one side of a cube (used for diagnostic purposes)
void print_cube(char cube_side[])
{
  for (int i = 0; i < 1; i++)
  {
    Serial.println('\r');
  }
  Serial.print("Face: ");
  Serial.println(cube_side[4]);

  for (int i = 0; i < 9; i = i + 3)
  {
    Serial.print("|");
    Serial.print(cube_side[i]);
    Serial.print("|");
    Serial.print(cube_side[i + 1]);
    Serial.print("|");
    Serial.print(cube_side[i + 2]);
    Serial.println("|");
  }
}
// prints all six sides of the cube
void print_whole_cube()
{
  print_cube(yellow_side);
  print_cube(white_side);
  print_cube(blue_side);
  print_cube(red_side);
  print_cube(green_side);
  print_cube(orange_side);
}

///////// Motors movement functions: ////////////
int a;
void left()
{ nOFm++;
  Serial.print("L, ");
   delay(1500);
  char r_yellow_side[9];
  char r_blue_side[9];
  char r_white_side[9];
  char r_green_side[9];
  char r_red_side[9];

  for (int i = 0; i < 9; i++)
  {
    r_yellow_side[i] = yellow_side[i];
  }
  for (int i = 0; i < 9; i++)
  {
    r_blue_side[i] = blue_side[i];
  }
  for (int i = 0; i < 9; i++)
  {
    r_white_side[i] = white_side[i];
  }
  for (int i = 0; i < 9; i++)
  {
    r_green_side[i] = green_side[i];
  }

  yellow_side[0] = r_blue_side[0];
  yellow_side[3] = r_blue_side[3];
  yellow_side[6] = r_blue_side[6];

  blue_side[0] = r_white_side[0];
  blue_side[3] = r_white_side[3];
  blue_side[6] = r_white_side[6];

  white_side[0] = r_green_side[8];
  white_side[3] = r_green_side[5];
  white_side[6] = r_green_side[2];

  green_side[8] = r_yellow_side[0];
  green_side[5] = r_yellow_side[3];
  green_side[2] = r_yellow_side[6];

  for (int x = 0; x < 9; x++)
  {
    r_red_side[x] = red_side[x];
  }

  red_side[0] = r_red_side[6];
  red_side[1] = r_red_side[3];
  red_side[2] = r_red_side[0];
  red_side[3] = r_red_side[7];
  red_side[4] = r_red_side[4];
  red_side[5] = r_red_side[1];
  red_side[6] = r_red_side[8];
  red_side[7] = r_red_side[5];
  red_side[8] = r_red_side[2];
  /*LStepper.step(10);
  delay(200);
  LStepper.step(10);
  delay(200);

  LStepper.step(10);
  delay(200);

  LStepper.step(10);
  delay(200);

  LStepper.step(12);
  delay(2000);
   /*FStepper.step(2);
  delay(200);
  FStepper.step(54);
  delay(200);
   FStepper.step(-2);
  delay(2000);
  */
    LStepper.step(2.8);
  delay(200);
   LStepper.step(51);
   delay(100);
   LStepper.step(-4);
 
  
  delay(3000);
}
void left_inverted()
{ nOFm++;
  Serial.print("L', ");
   //delay(1500);
  char r_yellow_side[9];
  char r_blue_side[9];
  char r_white_side[9];
  char r_green_side[9];
  char r_red_side[9];
  for (int i = 0; i < 9; i++)
  {
    r_yellow_side[i] = yellow_side[i];
  }
  for (int i = 0; i < 9; i++)
  {
    r_blue_side[i] = blue_side[i];
  }
  for (int i = 0; i < 9; i++)
  {
    r_white_side[i] = white_side[i];
  }
  for (int i = 0; i < 9; i++)
  {
    r_green_side[i] = green_side[i];
  }

  yellow_side[0] = r_green_side[8];
  yellow_side[3] = r_green_side[5];
  yellow_side[6] = r_green_side[2];

  blue_side[0] = r_yellow_side[0];
  blue_side[3] = r_yellow_side[3];
  blue_side[6] = r_yellow_side[6];

  white_side[0] = r_blue_side[0];
  white_side[3] = r_blue_side[3];
  white_side[6] = r_blue_side[6];

  green_side[8] = r_white_side[0];
  green_side[5] = r_white_side[3];
  green_side[2] = r_white_side[6];

  for (int x = 0; x < 9; x++)
  {
    r_red_side[x] = red_side[x];
  }

  red_side[0] = r_red_side[2];
  red_side[1] = r_red_side[5];
  red_side[2] = r_red_side[8];
  red_side[3] = r_red_side[1];
  red_side[4] = r_red_side[4];
  red_side[5] = r_red_side[7];
  red_side[6] = r_red_side[0];
  red_side[7] = r_red_side[3];
  red_side[8] = r_red_side[6];
 /*LStepper.step(11);
  delay(200);
  LStepper.step(10);
  delay(200);

  LStepper.step(10);
  delay(200);

  LStepper.step(10);
  delay(200);
   LStepper.step(12);
   delay(200);
    LStepper.step(-4);
   delay(2000);*/
   /* LStepper.step(-1);
  delay(200);
  LStepper.step(-54);
  delay(200);
   LStepper.step(2);
  delay(2000);*/
    LStepper.step(-2.8);
  delay(200);
   LStepper.step(-51);
   delay(100);
   LStepper.step(4);
  delay(3000);
  
}

int rr=1;
void right()
{ nOFm++;
  Serial.print("R, ");
   //delay(1500);
   char r_yellow_side[9];
  char r_blue_side[9];
  char r_white_side[9];
  char r_green_side[9];
  char r_orange_side[9];
  for(int i = 0; i < 9; i++)
  {
    r_yellow_side[i] = yellow_side[i];
  }
  for(int i = 0; i < 9; i++)
  {
    r_blue_side[i] = blue_side[i];
  }
  for(int i = 0; i < 9; i++)
  {
    r_white_side[i] = white_side[i];
  }
  for(int i = 0; i < 9; i++)
  {
    r_green_side[i] = green_side[i];
  }

  yellow_side[2] = r_green_side[6];
  yellow_side[5] = r_green_side[3];
  yellow_side[8] = r_green_side[0];

  blue_side[2] = r_yellow_side[2];
  blue_side[5] = r_yellow_side[5];
  blue_side[8] = r_yellow_side[8];

  white_side[2] = r_blue_side[2];
  white_side[5] = r_blue_side[5];
  white_side[8] = r_blue_side[8];

  green_side[6] = r_white_side[2];
  green_side[3] = r_white_side[5];
  green_side[0] = r_white_side[8];

  for(int x = 0; x < 9; x++)
  {
    r_orange_side[x] = orange_side[x];
  }

  orange_side[0] = r_orange_side[6];
  orange_side[1] = r_orange_side[3];
  orange_side[2] = r_orange_side[0];
  orange_side[3] = r_orange_side[7];
  orange_side[4] = r_orange_side[4];
  orange_side[5] = r_orange_side[1];
  orange_side[6] = r_orange_side[8];
  orange_side[7] = r_orange_side[5];
  orange_side[8] = r_orange_side[2];
   
  /* RStepper.step(10);
  delay(200);
   RStepper.step(1);
  delay(200);
  RStepper.step(10);
  delay(200);

  RStepper.step(10);
  delay(200);

  RStepper.step(10);
  delay(200);
   RStepper.step(12);
   delay(500);
    RStepper.step(-3);
   delay(3000);*/
  RStepper.step(3.5);
  delay(200);
   RStepper.step(51.6);
   delay(100);
   
   RStepper.step(-4);
  
  
  delay(2000);
}
int r=1;
void right_inverted()
{ nOFm++;
  Serial.print("R', ");
   //delay(1500);
 char r_yellow_side[9];
  char r_blue_side[9];
  char r_white_side[9];
  char r_green_side[9];
  char r_orange_side[9];
  for(int i = 0; i < 9; i++)
  {
    r_yellow_side[i] = yellow_side[i];
  }
  for(int i = 0; i < 9; i++)
  {
    r_blue_side[i] = blue_side[i];
  }
  for(int i = 0; i < 9; i++)
  {
    r_white_side[i] = white_side[i];
  }
  for(int i = 0; i < 9; i++)
  {
    r_green_side[i] = green_side[i];
  }

  yellow_side[2] = r_blue_side[2];
  yellow_side[5] = r_blue_side[5];
  yellow_side[8] = r_blue_side[8];

  blue_side[2] = r_white_side[2];
  blue_side[5] = r_white_side[5];
  blue_side[8] = r_white_side[8];

  white_side[2] = r_green_side[6];
  white_side[5] = r_green_side[3];
  white_side[8] = r_green_side[0];

  green_side[6] = r_yellow_side[2];
  green_side[3] = r_yellow_side[5];
  green_side[0] = r_yellow_side[8];

  for(int x = 0; x < 9; x++)
  {
    r_orange_side[x] = orange_side[x];
  }

  orange_side[0] = r_orange_side[2];
  orange_side[1] = r_orange_side[5];
  orange_side[2] = r_orange_side[8];
  orange_side[3] = r_orange_side[1];
  orange_side[4] = r_orange_side[4];
  orange_side[5] = r_orange_side[7];
  orange_side[6] = r_orange_side[0];
  orange_side[7] = r_orange_side[3];
  orange_side[8] = r_orange_side[6];
/* RStepper.step(-10);
  delay(200);
   RStepper.step(-1);
  delay(200);
  RStepper.step(-10);
  delay(200);

  RStepper.step(-10);
  delay(200);

  RStepper.step(-10);
  delay(200);
   RStepper.step(-12);
   delay(500);
    RStepper.step(3);
   delay(3000);*/
    // step one revolution  in one direction:
    RStepper.step(-3.5);
  delay(200);
   RStepper.step(-51.6);
   delay(100);
   
   RStepper.step(4);
  delay(2500);
}
int s=1;
void down()
{ nOFm++;
  Serial.print("D, ");
   //delay(1500);
  char r_yellow_side[9];
  char r_white_side[9];
  char r_orange_side[9];
  char r_red_side[9];
  char r_green_side[9];
  for(int i = 0; i < 9; i++)
  {
    r_yellow_side[i] = yellow_side[i];
  }
  for(int i = 0; i < 9; i++)
  {
    r_orange_side[i] = orange_side[i];
  }
  for(int i = 0; i < 9; i++)
  {
    r_white_side[i] = white_side[i];
  }
  for(int i = 0; i < 9; i++)
  {
    r_red_side[i] = red_side[i];
  }

  orange_side[8] = r_yellow_side[6];
  orange_side[5] = r_yellow_side[7];
  orange_side[2] = r_yellow_side[8];

  yellow_side[6] = r_red_side[0];
  yellow_side[7] = r_red_side[3];
  yellow_side[8] = r_red_side[6];

  red_side[0] = r_white_side[2];
  red_side[3] = r_white_side[1];
  red_side[6] = r_white_side[0];

  white_side[0] = r_orange_side[2];
  white_side[1] = r_orange_side[5];
  white_side[2] = r_orange_side[8];

  for(int x = 0; x < 9; x++)
  {
    r_green_side[x] = green_side[x];
  }
  // reassign colours on face
  green_side[0] = r_green_side[6];
  green_side[1] = r_green_side[3];
  green_side[2] = r_green_side[0];
  green_side[3] = r_green_side[7];
  green_side[4] = r_green_side[4];
  green_side[5] = r_green_side[1];
  green_side[6] = r_green_side[8];
  green_side[7] = r_green_side[5];
  green_side[8] = r_green_side[2];
  /*if(s<=1)
  DStepper.step(12);
  else 
  DStepper.step(10);
  delay(200);
   DStepper.step(1);
  delay(200);
  DStepper.step(10);
  delay(200);

  DStepper.step(10);
  delay(200);

  DStepper.step(10);
  delay(200);
   DStepper.step(13);
   delay(500);
    DStepper.step(-3);
   delay(3000);*/
 DStepper.step(4);
  delay(200);
   DStepper.step(51.5);
   delay(100);
   
   DStepper.step(-4);
 
  delay(5000);
}
void down_inverted()
{ nOFm++;
  Serial.print("D', ");
   //delay(1500);
  // Cube simulation
  char r_yellow_side[9];
  char r_white_side[9];
  char r_orange_side[9];
  char r_red_side[9];
  char r_green_side[9];
  for(int i = 0; i < 9; i++)
  {
    r_yellow_side[i] = yellow_side[i];
  }
  for(int i = 0; i < 9; i++)
  {
    r_orange_side[i] = orange_side[i];
  }
  for(int i = 0; i < 9; i++)
  {
    r_white_side[i] = white_side[i];
  }
  for(int i = 0; i < 9; i++)
  {
    r_red_side[i] = red_side[i];
  }

  yellow_side[6] = r_orange_side[8];
  yellow_side[7] = r_orange_side[5];
  yellow_side[8] = r_orange_side[2];

  red_side[0] = r_yellow_side[6];
  red_side[3] = r_yellow_side[7];
  red_side[6] = r_yellow_side[8];

  white_side[0] = r_red_side[6];
  white_side[1] = r_red_side[3];
  white_side[2] = r_red_side[0];

  orange_side[2] = r_white_side[0];
  orange_side[5] = r_white_side[1];
  orange_side[8] = r_white_side[2];

  for(int x = 0; x < 9; x++)
  {
    r_green_side[x] = green_side[x];
  }

  green_side[0] = r_green_side[2];
  green_side[1] = r_green_side[5];
  green_side[2] = r_green_side[8];
  green_side[3] = r_green_side[1];
  green_side[4] = r_green_side[4];
  green_side[5] = r_green_side[7];
  green_side[6] = r_green_side[0];
  green_side[7] = r_green_side[3];
  green_side[8] = r_green_side[6];
 /*DStepper.step(-10);
  delay(200);
   DStepper.step(-1);
  delay(200);
  DStepper.step(-10);
  delay(200);

  DStepper.step(-10);
  delay(200);

  DStepper.step(-10);
  delay(200);
   DStepper.step(-13);
   delay(500);
    DStepper.step(4);
   delay(3000);*/
  DStepper.step(-3);
  delay(200);
 
   DStepper.step(-51);
   delay(100);
   
   DStepper.step(4);
  delay(5000);
}
void up()
{ nOFm++;
  Serial.print("U, ");
   //delay(1500);
  char r_yellow_side[9];
  char r_white_side[9];
  char r_orange_side[9];
  char r_red_side[9];
  char r_blue_side[9];
  for (int i = 0; i < 9; i++)
  {
    r_yellow_side[i] = yellow_side[i];
  }
  for (int i = 0; i < 9; i++)
  {
    r_orange_side[i] = orange_side[i];
  }
  for (int i = 0; i < 9; i++)
  {
    r_white_side[i] = white_side[i];
  }
  for (int i = 0; i < 9; i++)
  {
    r_red_side[i] = red_side[i];
  }

  yellow_side[0] = r_orange_side[6];
  yellow_side[1] = r_orange_side[3];
  yellow_side[2] = r_orange_side[0];

  red_side[2] = r_yellow_side[0];
  red_side[5] = r_yellow_side[1];
  red_side[8] = r_yellow_side[2];

  white_side[6] = r_red_side[8];
  white_side[7] = r_red_side[5];
  white_side[8] = r_red_side[2];

  orange_side[0] = r_white_side[6];
  orange_side[3] = r_white_side[7];
  orange_side[6] = r_white_side[8];

  for (int x = 0; x < 9; x++)
  {
    r_blue_side[x] = blue_side[x];
  }

  blue_side[0] = r_blue_side[6];
  blue_side[1] = r_blue_side[3];
  blue_side[2] = r_blue_side[0];
  blue_side[3] = r_blue_side[7];
  blue_side[4] = r_blue_side[4];
  blue_side[5] = r_blue_side[1];
  blue_side[6] = r_blue_side[8];
  blue_side[7] = r_blue_side[5];
  blue_side[8] = r_blue_side[2];

  /*  UStepper.step(10.5);
  delay(200);
   UStepper.step(1.2);
  delay(200);
  UStepper.step(10);
  delay(200);

  UStepper.step(10);
  delay(200);

  UStepper.step(10);
  delay(200);
   UStepper.step(12);
   delay(500);
    UStepper.step(-3);
  delay(2000);*/
   /*UStepper.step(5);
  delay(200);
  
   UStepper.step(50);
   delay(100);
   
   UStepper.step(-4);
  
  delay(2000);*/
   UStepper.step(3);
  delay(200);
  
   UStepper.step(53);
   delay(100);
   
   UStepper.step(-6.5);
  
  delay(3000);
}
void up_inverted()
{ nOFm++;
  Serial.print("U', ");
   //delay(1500);
  char r_yellow_side[9];
  char r_white_side[9];
  char r_orange_side[9];
  char r_red_side[9];
  char r_blue_side[9];
  for (int i = 0; i < 9; i++)
  {
    r_yellow_side[i] = yellow_side[i];
  }
  for (int i = 0; i < 9; i++)
  {
    r_orange_side[i] = orange_side[i];
  }
  for (int i = 0; i < 9; i++)
  {
    r_white_side[i] = white_side[i];
  }
  for (int i = 0; i < 9; i++)
  {
    r_red_side[i] = red_side[i];
  }

  orange_side[6] = r_yellow_side[0];
  orange_side[3] = r_yellow_side[1];
  orange_side[0] = r_yellow_side[2];

  yellow_side[0] = r_red_side[2];
  yellow_side[1] = r_red_side[5];
  yellow_side[2] = r_red_side[8];

  red_side[2] = r_white_side[8];
  red_side[5] = r_white_side[7];
  red_side[8] = r_white_side[6];

  white_side[8] = r_orange_side[6];
  white_side[7] = r_orange_side[3];
  white_side[6] = r_orange_side[0];

  for (int x = 0; x < 9; x++)
  {
    r_blue_side[x] = blue_side[x];
  }

  blue_side[0] = r_blue_side[2];
  blue_side[1] = r_blue_side[5];
  blue_side[2] = r_blue_side[8];
  blue_side[3] = r_blue_side[1];
  blue_side[4] = r_blue_side[4];
  blue_side[5] = r_blue_side[7];
  blue_side[6] = r_blue_side[0];
  blue_side[7] = r_blue_side[3];
  blue_side[8] = r_blue_side[6];

   /*UStepper.step(-10);
  delay(200);
   UStepper.step(-1);
  delay(200);
  UStepper.step(-10);
  delay(200);

  UStepper.step(-10);
  delay(200);

  UStepper.step(-10);
  delay(200);
   UStepper.step(-12);
   delay(500);
    UStepper.step(3);
  delay(2000);(*/
   UStepper.step(-3);
  delay(200);
  
   UStepper.step(-53);
   delay(100);
   
   UStepper.step(6.5);
  
  delay(3000);
}
void front()
{ nOFm++;
  Serial.print("F, ");
   //delay(1500);
  char r_blue_side[9];
  char r_orange_side[9];
  char r_green_side[9];
  char r_red_side[9];
  char r_yellow_side[9];
  for (int i = 0; i < 9; i++)
  {
    r_blue_side[i] = blue_side[i];
  }
  for (int i = 0; i < 9; i++)
  {
    r_orange_side[i] = orange_side[i];
  }
  for (int i = 0; i < 9; i++)
  {
    r_green_side[i] = green_side[i];
  }
  for (int i = 0; i < 9; i++)
  {
    r_red_side[i] = red_side[i];
  }

  blue_side[6] = r_red_side[6];
  blue_side[7] = r_red_side[7];
  blue_side[8] = r_red_side[8];

  red_side[6] = r_green_side[6];
  red_side[7] = r_green_side[7];
  red_side[8] = r_green_side[8];

  green_side[6] = r_orange_side[6];
  green_side[7] = r_orange_side[7];
  green_side[8] = r_orange_side[8];

  orange_side[6] = r_blue_side[6];
  orange_side[7] = r_blue_side[7];
  orange_side[8] = r_blue_side[8];


  for (int x = 0; x < 9; x++)
  {
    r_yellow_side[x] = yellow_side[x];
  }

  yellow_side[0] = r_yellow_side[6];
  yellow_side[1] = r_yellow_side[3];
  yellow_side[2] = r_yellow_side[0];
  yellow_side[3] = r_yellow_side[7];
  yellow_side[4] = r_yellow_side[4];
  yellow_side[5] = r_yellow_side[1];
  yellow_side[6] = r_yellow_side[8];
  yellow_side[7] = r_yellow_side[5];
  yellow_side[8] = r_yellow_side[2];

   /* FStepper.step(10);
  delay(200);
   FStepper.step(1);
  delay(200);
  FStepper.step(10);
  delay(200);

  FStepper.step(10);
  delay(200);

  FStepper.step(10);
  delay(200);
   FStepper.step(12);
   delay(500);
    FStepper.step(-3);
  delay(2000);*/
      FStepper.step(1.5);
  delay(200);
  
   FStepper.step(51);
   delay(100);
   
   FStepper.step(-1);
  delay(2500);
}
void front_inverted()
{ nOFm++;
  Serial.print("F', ");
   //delay(1500);
  char r_blue_side[9];
  char r_orange_side[9];
  char r_green_side[9];
  char r_red_side[9];
  char r_yellow_side[9];
  for (int i = 0; i < 9; i++)
  {
    r_blue_side[i] = blue_side[i];
  }
  for (int i = 0; i < 9; i++)
  {
    r_orange_side[i] = orange_side[i];
  }
  for (int i = 0; i < 9; i++)
  {
    r_green_side[i] = green_side[i];
  }
  for (int i = 0; i < 9; i++)
  {
    r_red_side[i] = red_side[i];
  }

  blue_side[6] = r_orange_side[6];
  blue_side[7] = r_orange_side[7];
  blue_side[8] = r_orange_side[8];

  red_side[6] = r_blue_side[6];
  red_side[7] = r_blue_side[7];
  red_side[8] = r_blue_side[8];

  green_side[6] = r_red_side[6];
  green_side[7] = r_red_side[7];
  green_side[8] = r_red_side[8];

  orange_side[6] = r_green_side[6];
  orange_side[7] = r_green_side[7];
  orange_side[8] = r_green_side[8];

  for (int x = 0; x < 9; x++)
  {
    r_yellow_side[x] = yellow_side[x];
  }

  yellow_side[0] = r_yellow_side[2];
  yellow_side[1] = r_yellow_side[5];
  yellow_side[2] = r_yellow_side[8];
  yellow_side[3] = r_yellow_side[1];
  yellow_side[4] = r_yellow_side[4];
  yellow_side[5] = r_yellow_side[7];
  yellow_side[6] = r_yellow_side[0];
  yellow_side[7] = r_yellow_side[3];
  yellow_side[8] = r_yellow_side[6];

 /* FStepper.step(-10);
  delay(200);
   FStepper.step(-1);
  delay(200);
  FStepper.step(-10);
  delay(200);

  FStepper.step(-10);
  delay(200);

  FStepper.step(-10);
  delay(200);
   FStepper.step(-12);
   delay(500);
    FStepper.step(3);
   delay(2000);*/
   FStepper.step(-1.5);
  delay(200);
  
   FStepper.step(-51);
   delay(100);
   
   FStepper.step(1);
  
  
  delay(2500);
  
}


void back()
{ nOFm++;
  Serial.print("B, ");
   //delay(1500);
 // Cube simulation
  char r_blue_side[9];
  char r_orange_side[9];
  char r_green_side[9];
  char r_red_side[9];
  char r_white_side[9];
  for(int i = 0; i < 9; i++)
  {
    r_blue_side[i] = blue_side[i];
  }
  for(int i = 0; i < 9; i++)
  {
    r_orange_side[i] = orange_side[i];
  }
  for(int i = 0; i < 9; i++)
  {
    r_green_side[i] = green_side[i];
  }
  for(int i = 0; i < 9; i++)
  {
    r_red_side[i] = red_side[i];
  }

  blue_side[0] = r_orange_side[0];
  blue_side[1] = r_orange_side[1];
  blue_side[2] = r_orange_side[2];

  red_side[0] = r_blue_side[0];
  red_side[1] = r_blue_side[1];
  red_side[2] = r_blue_side[2];

  green_side[0] = r_red_side[0];
  green_side[1] = r_red_side[1];
  green_side[2] = r_red_side[2];

  orange_side[0] = r_green_side[0];
  orange_side[1] = r_green_side[1];
  orange_side[2] = r_green_side[2];

  for(int x = 0; x < 9; x++)
  {
    r_white_side[x] = white_side[x];
  }

  white_side[0] = r_white_side[6];
  white_side[1] = r_white_side[3];
  white_side[2] = r_white_side[0];
  white_side[3] = r_white_side[7];
  white_side[4] = r_white_side[4];
  white_side[5] = r_white_side[1];
  white_side[6] = r_white_side[8];
  white_side[7] = r_white_side[5];
  white_side[8] = r_white_side[2];
     /*BStepper.step(1);
   delay(200);
  BStepper.step(10.5);
  delay(200);
  
  BStepper.step(10);
  delay(200);

  BStepper.step(10);
  delay(200);

  BStepper.step(10);
  delay(200);
  if(a<1)
  BStepper.step(15);
  else{
   BStepper.step(12);}
   
   delay(500);
    BStepper.step(-3);
   delay(3500);*/
   BStepper.step(3.5);
  delay(200);
   BStepper.step(51.6);
   delay(100);
   
   BStepper.step(-4);
  
  delay(2500);
 
}

void back_inverted()
{ nOFm++;
  Serial.print("B', ");
   //delay(1500);
  char r_blue_side[9];
  char r_orange_side[9];
  char r_green_side[9];
  char r_red_side[9];
  char r_white_side[9];
  for(int i = 0; i < 9; i++)
  {
    r_blue_side[i] = blue_side[i];
  }
  for(int i = 0; i < 9; i++)
  {
    r_orange_side[i] = orange_side[i];
  }
  for(int i = 0; i < 9; i++)
  {
    r_green_side[i] = green_side[i];
  }
  for(int i = 0; i < 9; i++)
  {
    r_red_side[i] = red_side[i];
  }

  blue_side[0] = r_red_side[0];
  blue_side[1] = r_red_side[1];
  blue_side[2] = r_red_side[2];

  red_side[0] = r_green_side[0];
  red_side[1] = r_green_side[1];
  red_side[2] = r_green_side[2];

  green_side[0] = r_orange_side[0];
  green_side[1] = r_orange_side[1];
  green_side[2] = r_orange_side[2];

  orange_side[0] = r_blue_side[0];
  orange_side[1] = r_blue_side[1];
  orange_side[2] = r_blue_side[2];

  for(int x = 0; x < 9; x++)
  {
    r_white_side[x] = white_side[x];
  }

  white_side[0] = r_white_side[2];
  white_side[1] = r_white_side[5];
  white_side[2] = r_white_side[8];
  white_side[3] = r_white_side[1];
  white_side[4] = r_white_side[4];
  white_side[5] = r_white_side[7];
  white_side[6] = r_white_side[0];
  white_side[7] = r_white_side[3];
  white_side[8] = r_white_side[6];
 /* BStepper.step(-1);
   delay(200);
  BStepper.step(-10);
  delay(200);
  
  BStepper.step(-10);
  delay(200);

  BStepper.step(-10);
  delay(200);

  BStepper.step(-10);
  delay(200);
  if(a<1)
  BStepper.step(-15);
  else{
   BStepper.step(-12);}
   
   delay(500);
    BStepper.step(3);
   delay(3500);*/
 BStepper.step(-3.5);
  delay(200);
   BStepper.step(-51.6);
   delay(100);
   
   BStepper.step(4);
  
  delay(3000);
}

//////////// Cube Algorithms ///////////

void fix_cross_instance_up_right() // bad pieces up and right
{
  Serial.println();
  Serial.print("  Fix Cross Instance 1: ");
  right(); right();
  back();
  up(); up();
  back_inverted();
  right(); right();
}

void fix_cross_instance_up_down() // bad pieces up and down
{
  Serial.println();
  Serial.print("  Fix Cross Instance 2: ");
  up(); up();
  back(); back();
  down(); down();
  back(); back();
  up(); up();
}
void fix_cross_right_left() // bad pieces right and left
{
  Serial.println("  fix_cross_right_left: ");
  right(); right();
  back(); back();
  left(); left();
  back(); back();
  right(); right();
}

void fix_cross_down_right() // bad pieces _down_left
{
  Serial.println();
  Serial.print("  Fix Cross Instance 2: ");
  right(); right();
  back_inverted();
  down(); down();
  back();
  right(); right();
}

void fix_cross_down_left() // bad pieces _down_left
{
  Serial.println();
  Serial.print("  Fix Cross Instance 2: ");
  left(); left();
  back();
  down(); down();
  back_inverted();
  left(); left();
}


void fix_cross_left_up() // bad pieces left_up
{
  Serial.println();
  Serial.print("  Fix Cross Instance 2: ");
  left(); left();
  back_inverted();
  up(); up();
  back();
  left(); left();
}




//////////////////////////////// cube_decide functions, used to determine what algorithms and moves to execute /////////////////////
int solve_stage = 1;
bool cube_solved = true;

void cube_decide_cross()
{
  Serial.println();
  Serial.println();
  Serial.print("Cross: ");
  if (yellow_side[1] == 'y' &&
      yellow_side[3] == 'y' &&
      yellow_side[5] == 'y' &&
      yellow_side[7] == 'y')
  {
    solve_stage = 2;
    print_whole_cube();
    Serial.print("Cross_Solved.");
    //test_ongoing = false;
  }
  ///////////// move the pieces from the sides up /////////////// /// should turn this into a function later(blue_side, moves)
  else if (solve_stage == 1)
  {
    // move from blue_side[3]
    if (blue_side[3] == 'y')
    {
      for (int x = 0; x < 3; x++) // rotate cube four times, or until there is an empty space
      {
        if (yellow_side[3] != 'y')
        {
          left();
          x = 3; // end loop since yellow piece has reached the top
        }
        else
        {
          front();
        }
      }
    }
    // move from blue_side[5]
    else if (blue_side[5] == 'y')
    {
      for (int x = 0; x < 3; x++) // rotate cube four times, or until there is an empty space
      {
        if (yellow_side[5] != 'y')
        {
          right_inverted();
          x = 3; // end loop since yellow piece has reached the top
        }
        else
        {
          front();
        }
      }
    }
    // move from red_side[5]
    else if (red_side[5] == 'y')
    {
      for (int x = 0; x < 3; x++) // rotate cube four times, or until there is an empty space
      {
        if (yellow_side[1] != 'y')
        {
          up_inverted();
          x = 3; // end loop since yellow piece has reached the top
        }
        else
        {
          front();
        }
      }
    }
    // move from red_side[3]
    else if (red_side[3] == 'y')
    {
      for (int x = 0; x < 3; x++) // rotate cube four times, or until there is an empty space
      {
        if (yellow_side[7] != 'y')
        {
          down();
          x = 3; // end loop since yellow piece has reached the top
        }
        else
        {
          front();
        }
      }
    }
    // move from green_side[5]
    else if (green_side[5] == 'y')
    {
      for (int x = 0; x < 3; x++) // rotate cube four times, or until there is an empty space
      {
        if (yellow_side[3] != 'y')
        {
          left_inverted();
          x = 3; // end loop since yellow piece has reached the top
        }
        else
        {
          front();
        }
      }
    }

    // move from green_side[3]
    else if (green_side[3] == 'y')
    {
      for (int x = 0; x < 3; x++) // rotate cube four times, or until there is an empty space
      {
        if (yellow_side[5] != 'y')
        {
          right();
          x = 3; // end loop since yellow piece has reached the top
        }
        else
        {
          front();
        }
      }
    }
    // move from orange_side[5]
    else if (orange_side[5] == 'y')
    {
      for (int x = 0; x < 3; x++) // rotate cube four times, or until there is an empty space
      {
        if (yellow_side[7] != 'y')
        {
          down_inverted();
          x = 3; // end loop since yellow piece has reached the top
        }
        else
        {
          front();
        }
      }
    }
    // move from orange_side[3]
    else if (orange_side[3] == 'y')
    {
      for (int x = 0; x < 3; x++) // rotate cube four times, or until there is an empty space
      {
        if (yellow_side[1] != 'y')
        {
          up();
          x = 3; // end loop since yellow piece has reached the top
        }
        else
        {
          front();
        }
      }
    }
    // move from white_side[1]
    else if (white_side[1] == 'y')
    {
      for (int x = 0; x < 3; x++) // rotate cube four times, or until there is an empty space
      {
        if (yellow_side[7] != 'y')
        {
          down();
          down();
          x = 3; // end loop since yellow piece has reached the top
        }
        else
        {
          front();
        }
      }
    }
    // move from white_side[7]
    else if (white_side[7] == 'y')
    {
      for (int x = 0; x < 3; x++) // rotate cube four times, or until there is an empty space
      {
        if (yellow_side[1] != 'y')
        {
          up();
          up();
          x = 3; // end loop since yellow piece has reached the top
        }
        else
        {
          front();
        }
      }
    }
    // move from white_side[3]
    else if (white_side[3] == 'y')
    {
      for (int x = 0; x < 3; x++) // rotate cube four times, or until there is an empty space
      {
        if (yellow_side[3] != 'y')
        {
          left();
          left();
          x = 3; // end loop since yellow piece has reached the top
        }
        else
        {
          front();
        }
      }
    }
    // move from white_side[5]
    else if (white_side[5] == 'y')
    {
      for (int x = 0; x < 3; x++) // rotate cube four times, or until there is an empty space
      {
        if (yellow_side[5] != 'y')
        {
          right();
          right();
          x = 3; // end loop since yellow piece has reached the top
        }
        else
        {
          front();
        }
      }
    }
    /////////////////
    //////////////
    ///////////////////////// get the piece from 2- move spots, like blue_side[7]
    // blue_side[1]
    else if (blue_side[1] == 'y')
    {
      for (int x = 0; x < 3; x++) // rotate cube four times, or until there is an empty space
      {
        if (yellow_side[1] != 'y')
        {
          up();
          front();
          right_inverted();
          x = 3; // end loop since yellow piece has reached the top
        }
        else
        {
          front();
        }
      }
    }
    // blue_side[7]
    else if (blue_side[7] == 'y')
    {
      if (yellow_side[1] != 'y')
      {
        up_inverted();
        front();
        right_inverted();
      }
      else
      {
        up_inverted();
      }
    }
    // red_side[1]
    else if (red_side[1] == 'y')
    {
      for (int x = 0; x < 3; x++) // rotate cube four times, or until there is an empty space
      {
        if (yellow_side[3] != 'y')
        {
          left();
          front();
          up_inverted();
          x = 3; // end loop since yellow piece has reached the top
        }
        else
        {
          front();
        }
      }
    }
    // red_side[7]
    else if (red_side[7] == 'y')
    {
      if (yellow_side[3] != 'y')
      {
        left_inverted();
        front();
        up_inverted();
      }
      else
      {
        left_inverted();
      }
    }
    // green_side[1]
    else if (green_side[1] == 'y')
    {
      for (int x = 0; x < 3; x++) // rotate cube four times, or until there is an empty space
      {
        if (yellow_side[7] != 'y')
        {
          down();
          front();
          left_inverted();
          x = 3; // end loop since yellow piece has reached the top
        }
        else
        {
          front();
        }
      }
    }
    // green_side[7]
    else if (green_side[7] == 'y')
    {
      if (yellow_side[7] != 'y')
      {
        down();
        front_inverted();
        right();
      }
      else
      {
        down();
      }
    }
    // orange_side[1]
    else if (orange_side[1] == 'y')
    {
      for (int x = 0; x < 3; x++) // rotate cube four times, or until there is an empty space
      {
        if (yellow_side[5] != 'y')
        {
          right();
          front();
          down_inverted();
          x = 3; // end loop since yellow piece has reached the top
        }
        else
        {
          front();
        }
      }
    }
    // green_side[7]
    else if (orange_side[7] == 'y')
    {
      if (yellow_side[5] != 'y')
      {
        right_inverted();
        front();
        down_inverted();
      }
      else
      {
        right_inverted();
      }
    }
  }
}

void cube_decide_whole_cross()
{
  Serial.println();
  Serial.println();
  Serial.print("Whole Cross: ");
  if (solve_stage == 2 &&
      blue_side[7] == 'b' &&
      red_side[7] == 'r' &&
      green_side[7] == 'g' &&
      orange_side[7] == 'o')
  {  print_whole_cube();
    Serial.print("Solved.");
    solve_stage = 3;
  }
  // green and orange are good
  else if (solve_stage == 2 && blue_side[7] != 'b' && red_side[7] != 'r' && green_side[7] == 'g' && orange_side[7] == 'o')
  {
    fix_cross_left_up();
  }
  // red and orange are good
  else if (solve_stage == 2 && blue_side[7] != 'b' && red_side[7] == 'r' && green_side[7] != 'g' && orange_side[7] == 'o')
  {
    fix_cross_instance_up_down();
  }
  // red and green are good
  else if (solve_stage == 2 == true && blue_side[7] != 'b' && red_side[7] == 'r' && green_side[7] == 'g' && orange_side[7] != 'o')
  {
    fix_cross_instance_up_right();
  }
  // blue and orange are good
  else if (solve_stage == 2 && blue_side[7] == 'b' && red_side[7] != 'r' && green_side[7] != 'g' && orange_side[7] == 'o')
  {
    fix_cross_down_left();
  }
  // blue and green are good
  else if (solve_stage == 2 && blue_side[7] == 'b' && red_side[7] != 'r' && green_side[7] == 'g' && orange_side[7] != 'o')
  {
    fix_cross_right_left();
  }
  // red and blue are good
  else if (solve_stage == 2 && blue_side[7] == 'b' && red_side[7] == 'r' && green_side[7] != 'g' && orange_side[7] != 'o')
  {
    fix_cross_down_right();
    
  }
  // none match, cross in done but whole cross isn't
  else if (solve_stage == 2)
  {
    front();
  }
  else
  {
    Serial.println("Error in whole_cross");
  }
}





int shady(){
if((blue_side[8]=='b' && orange_side[6]=='r' && yellow_side[2]=='y')||
  (blue_side[8]=='b' && orange_side[6]=='y' && yellow_side[2]=='r')||
  (blue_side[8]=='r' && orange_side[6]=='b' && yellow_side[2]=='y')||
  (blue_side[8]=='r' && orange_side[6]=='y' && yellow_side[2]=='b')||
  (blue_side[8]=='y' && orange_side[6]=='b' && yellow_side[2]=='r')||
  (blue_side[8]=='y' && orange_side[6]=='r' && yellow_side[2]=='b')
  )
  return 1;

   else if((green_side [6]=='b' && orange_side[8]=='r' && yellow_side[8]=='y')||
  (green_side [6]=='b' && orange_side[8]=='y' && yellow_side[8]=='r')||
  (green_side [6]=='r' && orange_side[8]=='b' && yellow_side[8]=='y')||
  (green_side [6]=='r' && orange_side[8]=='y' && yellow_side[8]=='b')||
  (green_side [6]=='y' && orange_side[8]=='b' && yellow_side[8]=='r')||
  (green_side [6]=='y' && orange_side[8]=='r' && yellow_side[8]=='b')
  )
  return 2;

else if((green_side [8]=='b' && red_side[6]=='r' && yellow_side[6]=='y')||
  (green_side [8]=='b' && red_side[6]=='y' && yellow_side[6]=='r')||
  (green_side [8]=='r' && red_side[6]=='b' && yellow_side[6]=='y')||
  (green_side [8]=='r' && red_side[6]=='y' && yellow_side[6]=='b')||
  (green_side [8]=='y' && red_side[6]=='b' && yellow_side[6]=='r')||
  (green_side [8]=='y' && red_side[6]=='r' && yellow_side[6]=='b')
  )
  return 3;

 else return 0;
  
}

int F2Ledges_R_B(){

  if((blue_side[5]=='r' && orange_side[3]=='b')||     //b o
          (blue_side[5]=='b' && orange_side[3]=='r'))
          return 1;
  
  else if((green_side[3]=='r' && orange_side[5]=='b')||     //o g
          (green_side[3]=='b' && orange_side[5]=='r'))
          return 2;
          
   else if((green_side[5]=='r' && red_side[3]=='b')||     //g r
          (green_side[5]=='b' && red_side[3]=='r'))
          return 3;
   else   return 0;
  
  
  }
int i=1;
///////////////F2L REEEEEEED BLUEEEEEEEEEEEE/////////////
void cube_decide_F2L_RED_BLUE() {
  Serial.println();
  Serial.print("F2L_RED_BLUE: ");
  Serial.println();
  if (solve_stage == 3 &&
      red_side[8] == 'r' && red_side[5] == 'r' && blue_side[6] == 'b' && blue_side[3] == 'b' && yellow_side[0] == 'y')
  {  print_whole_cube();
    Serial.print(" F2L_RED_BLUE was Solved.");
    solve_stage = 4;
  }
  
 
  else if (solve_stage == 3) {
    int s=shady();
   
 
 while(i<2){
  i++;
  if (s==1) {right();back();right_inverted();}
  else if(s==2){down();back();back();down_inverted(); print_whole_cube();}
  else if(s==3){down_inverted();back_inverted();down(); print_whole_cube();}
  delay(3000);
  int s2=F2Ledges_R_B();
  if (s2==1){back();right();back_inverted();right_inverted();back_inverted();up_inverted();back();up(); print_whole_cube();}//b o
  else if(s2==2){back();down();back_inverted();down_inverted();back_inverted();right_inverted();back();right();}//o g
  else if(s2==3){back_inverted();down_inverted();back();down();back();left();back_inverted();left_inverted();}//g r
  Serial.println(s2);
  delay(3000);
 }
 

//////////Red_Blue corner////////////////////
    if (red_side[2]=='r' && blue_side[0]=='y' && white_side[6] == 'b' && white_side[5] == 'r' && orange_side[1]=='b') {
      up();
      back();
      up_inverted();
    }
    else if (red_side[2] == 'y' && blue_side[0] == 'b' && white_side[6] == 'r' && white_side[1] == 'b' && green_side[1] == 'r') {
      left_inverted();
      back_inverted();
      left();
    }
    else if (red_side[1] == 'r' && red_side[2] == 'r' && blue_side[0] == 'y' && white_side[6] == 'b' && white_side[3] == 'b') {
      back_inverted();
      left_inverted();
      back();
      left();
    }
    else if (white_side[6] == 'r' && white_side[7] == 'r' && red_side[2] == 'y' && blue_side[1] == 'b' && blue_side[0] == 'b') {
      back();
      up();
      back_inverted(); 
      up_inverted();
    }
    else if (blue_side[6] == 'b' && red_side[8] == 'r' && red_side[1] == 'r' && white_side[3] == 'b' && yellow_side[0] == 'y') {
      back();
      up();
      back_inverted(); 
      up_inverted();
      back_inverted();
      left_inverted();
      back();
      left();
    }
    else if (blue_side[6] == 'b' && blue_side[1] == 'b' && red_side[8] == 'r' && yellow_side[8] == 'r' && blue_side[7] == 'r') {
      back_inverted();
      left_inverted();
      back();
      left();
      back();
      up();
      back_inverted(); 
      up_inverted();
    }
    else if (blue_side[6] == 'y' && yellow_side[0] == 'r' && red_side[8] == 'b' && white_side[3] == 'b' && red_side[1] == 'r') {
      left_inverted();
      back();
      left();
      back_inverted();
      left_inverted();
      back();
      left();
    }
    else if (blue_side[6] == 'y' && yellow_side[0] == 'r' && red_side[8] == 'b' && white_side[7] == 'r' && blue_side[1] == 'b') {//8
      up();
      back();
      up_inverted();
      back_inverted();
      up();
      back();
      up_inverted();
    }
    else if (red_side[8] == 'y' && white_side[7] == 'r' && blue_side[6] == 'r' && yellow_side[0] == 'b' && blue_side[1] == 'b') {//9
      up();
      back_inverted();
      up_inverted();
      back();
      up();
      back_inverted(); 
      up_inverted();
    }
    
    else if (blue_side[6] == 'r' && red_side[8] == 'y' && yellow_side[0] == 'b' && white_side[3] == 'b' && red_side[1] == 'r') {//10
      left_inverted();
      back_inverted();
      left();
      back();
      left_inverted();
      back_inverted();
      left();
    }
    else if (blue_side[3] == 'b' && red_side[5] == 'r' && red_side[2] == 'b' && blue_side[0] == 'r' && white_side[6] == 'y') {//11
      up();
      back();
      up_inverted();
      back_inverted();
      up();
      back();
      up_inverted();
      back_inverted();
      up();
      back();
      up_inverted();
    }
    else if (blue_side[0] == 'r' && blue_side[3] == 'r' && red_side[5] == 'b' && white_side[6] == 'y' && red_side[2] == 'b') {//12
      up();
      back_inverted();
      up_inverted();
      back();
      left_inverted();
      back();
      left();
    }
    else if (red_side[2] == 'r' && red_side[5] == 'r' && blue_side[3] == 'b' && white_side[6] == 'b' && blue_side[0] == 'y') {//13
      back();
      left_inverted();
      back();
      left();
      back();
      left_inverted();
      back();
      back();
      left();
    }
    else if (blue_side[0] == 'y' && blue_side[3] == 'rr' && red_side[2] == 'r' && red_side[5] == 'b' && white_side[6] == 'b') {//14
      back();
      left_inverted();
      back_inverted();
      left();
      back_inverted();
      up();
      back();
      up_inverted();
    }
    else if (red_side[5] == 'r' && blue_side[0] == 'b' && red_side[2] == 'y' && blue_side[3] == 'b' && white_side[6] == 'r') {//15
      back_inverted();
      up();
      back_inverted();
      up_inverted();
      back_inverted();
      up();
      back();
      back();
      up_inverted();
      
    }
    else if (blue_side[0] == 'b' && red_side[2] == 'y' && blue_side[3] == 'r' && red_side[5] == 'b' && white_side[6] == 'r') {//16
      back_inverted();
      up();
      back();
      up_inverted();
      back();
      left_inverted();
      back_inverted();
      left();
    }
    else if (blue_side[0] == 'y' && white_side[6] == 'b' && red_side[2] == 'r' && blue_side[1] == 'r' && white_side[7] == 'b') {//17
      up();
      back_inverted();
      up_inverted();
      back();
      back();
      left_inverted();
      back_inverted();
      left();
    }
    else if (blue_side[0] == 'b' && red_side[1] == 'b' && red_side[2] == 'y' && white_side[6] == 'r' && white_side[3] == 'r') {//18
      left_inverted();
      back();
      left();
      back();
      back();
      up();
      back();
      up_inverted();
    }
    else if (blue_side[0] == 'y' && orange_side[1] == 'r' && white_side[6] == 'b' && white_side[5] == 'b' && red_side[2] == 'r') {//19
      back();
      left_inverted();
      back();
      back();
      left();
      back();
      left_inverted();
      back();
      back();
      left();
    }
    else if (red_side[2] == 'y' && green_side[1] == 'b' && white_side[6] == 'r' && white_side[1] == 'r' && blue_side[0] == 'b') {//20
      back_inverted();
      up();
      back();
      back();
      up_inverted();
      back_inverted();
      up();
      back();
      back();
      up_inverted();
    }
    else if (red_side[2] == 'r' && blue_side[0] == 'y' && white_side[6] == 'b' && white_side[1] == 'b' && green_side[1] == 'r') {//21
      back();
      left_inverted();
      back_inverted();
      left();
      back();
      left_inverted();
      back();
      back();
      left();
    }
    else if (red_side[2] == 'y' && blue_side[0] == 'b' && orange_side[1] == 'b' && white_side[6] == 'r' && white_side[5] == 'r') {//22
      back_inverted();
      up();
      back();
      up_inverted();
      back_inverted();
      up();
      back();
      back();
      up_inverted();
    }
    else if (red_side[2] == 'r' && white_side[6] == 'b' && blue_side[0] == 'y' && white_side[7] == 'r' && blue_side[1] == 'b') {//23
      back_inverted();
      up();
      back_inverted();
      up_inverted();
      back();
      up();
      back();
      up_inverted();
    }
    else if (red_side[2] == 'y' && blue_side[0] == 'b' && white_side[3] == 'b' && white_side[6] == 'r' && red_side[1] == 'r') {//24
      back();
      left_inverted();
      back();
      left();
      back_inverted();
      left_inverted();
      back_inverted();
      left();
    }
    else if (red_side[2] == 'r' && blue_side[0] == 'y' && green_side[1] == 'b' && white_side[6] == 'b' && white_side[1] == 'r') {//25
      back_inverted();
      up();
      back();
      up_inverted();
      back();
      up();
      back();
      up_inverted();
    }
    else if (red_side[2] == 'y' && blue_side[0] == 'b' && orange_side[1] == 'r' && white_side[6] == 'r' && white_side[5] == 'b') {//26
      back();
      left_inverted();
      back_inverted();
      left();
      back_inverted();
      left_inverted();
      back_inverted();
      left();
    }
    else if (red_side[1] == 'b' && blue_side[0] == 'y' && red_side[2] == 'r' && white_side[6] == 'b' && white_side[3] == 'r') {//27
      back();
      left_inverted();
      back();
      back();
      left();
      back_inverted();
      up();
      back();
      up_inverted();
    }
    else if (red_side[2] == 'y' && white_side[6] == 'r' && blue_side[0] == 'b' && blue_side[1] == 'r' && white_side[7] == 'b') {//28
      back_inverted();
      up();
      back();
      back();
      up_inverted();
      back();
      left_inverted();
      back_inverted();
      left();
    }
    else if (red_side[1] == 'b' && red_side[2] == 'b' && blue_side[0] == 'r' && white_side[6] == 'y' && white_side[3] == 'r') {//29
      up();
      back();
      up_inverted();
      back_inverted();
      back_inverted();
      up();
      back();
      up_inverted();
      back_inverted();
      up();
      back();
      up_inverted();
    }
    else if (red_side[2] == 'b' && blue_side[0] == 'r' && blue_side[1] == 'r' && white_side[6] == 'y' && white_side[7] == 'b') {//30
      left_inverted();
      back_inverted();
      left();
      back();
      back();
      left_inverted();
      back_inverted();
      left();
      back();
      left_inverted();
      back_inverted();
      left();
    }
    else if (red_side[2] == 'b' && blue_side[0] == 'r' && green_side[1] == 'b' && white_side[6] == 'y' && white_side[1] == 'r') {//31
      back();
      back();
      up();
      back();
      up_inverted();
      back();
      up();
      back_inverted();
      up_inverted();
    }
    else if (red_side[2] == 'b' && blue_side[0] == 'r' && orange_side[1] == 'r' && white_side[6] == 'y' && white_side[5] == 'b') {//32
      back();
      back();
      left_inverted();
      back_inverted();
      left();
      back_inverted();
      left_inverted();
      back();
      left();
    }
    else if (red_side[2] == 'b' && white_side[6] == 'y' && orange_side[1] == 'b' && blue_side[0] == 'r' && white_side[5] == 'r') {//33
      back();
      up();
      back();
      back();
      up_inverted();
      back();
      up();
      back_inverted();
      up_inverted();
     
    }
    else if (red_side[2] == 'b' && white_side[6] == 'y' && blue_side[0] == 'r' && green_side[1] == 'r' && white_side[1] == 'b') {//34
      back_inverted();
      left_inverted();
      back();
      back();
      left();
      back_inverted();
      left_inverted();
      back();
      left();
    }
    else if (red_side[2] == 'b' && white_side[6] == 'y' && blue_side[0] == 'r' && blue_side[1] == 'b' && white_side[7] == 'r') {//35
      up();
      back();
      back();
      up_inverted();
      back_inverted();
      up();
      back();
      up_inverted();
    }
    else if (red_side[2] == 'b' && red_side[1] == 'r' && blue_side[0] == 'r' && white_side[6] == 'y' && white_side[3] == 'b') {//36
      left_inverted();
      back();
      back();
      left();
      back();
      left_inverted();
      back_inverted();
      left();
    }
    else if (red_side[8] == 'r' && blue_side[6] == 'b' && blue_side[3] == 'r' && red_side[5] == 'b' && yellow_side[0] == 'y') {//37
      up();
      back_inverted();
      up_inverted();
      back();
      left_inverted();
      back();
      back();
      left();
      back();
      left_inverted();
      back();
      back();
      left();
    }
    else if (red_side[5] == 'r' && red_side[8] == 'b' && blue_side[6] == 'y' && blue_side[3] == 'b' && yellow_side[0] == 'r') {//38
      up();
      back_inverted();
      up_inverted();
      back();
      up();
      back();
      back();
      up_inverted();
      back();
      up();
      back_inverted();
      up_inverted();
    }
    else if (red_side[5] == 'r' && red_side[8] == 'y' && blue_side[6] == 'r' && blue_side[3] == 'b' && yellow_side[0] == 'b') {//39
      up();
      back_inverted();
      up_inverted();
      back_inverted();
      up();
      back();
      up_inverted();
      back_inverted();
      up();
      back();
      back();
      up_inverted();
    }
    else if (red_side[5] == 'b' && red_side[8] == 'b' && blue_side[6] == 'y' && blue_side[3] == 'r' && yellow_side[0] == 'r') {//40
      up();
      back();
      up_inverted();
      back_inverted();
      up();
      back_inverted();
      up_inverted();
      back();
      back();
      left_inverted();
      back_inverted();
      left();
    }
    else if (red_side[8] == 'y' && red_side[5] == 'b' && blue_side[6] == 'r' && blue_side[3] == 'r' && yellow_side[0] == 'b') {//41
      up();
      back_inverted();
      up_inverted();
      back();
      left_inverted();
      back_inverted();
      left();
      back_inverted();
      left_inverted();
      back_inverted();
      left();
    }
    
    else  {
      if (red_side[8] != 'r' || red_side[5] != 'r' || blue_side[6] != 'b' || blue_side[3] != 'b' || yellow_side[0] != 'y') {
      Serial.println("error in R B");
      //left_inverted();
      back();
      //left();
      delay(300);}
    }
 
   
}

  

 
  
    delay(100);

}



////////////F2L_BLUEEEEEEEE_ORANGEEEEEEEEE/////////////


int BOYcorner(){              ///finding the BLUE_ORANGE_YELLOW corner
if((blue_side[6]=='b' && red_side[8]=='o' && yellow_side[0]=='y')||
  (blue_side[6]=='b' && red_side[8]=='y' && yellow_side[0]=='o')||
  (blue_side[6]=='o' && red_side[8]=='b' && yellow_side[0]=='y')||
  (blue_side[6]=='o' && red_side[8]=='y' && yellow_side[0]=='b')||
  (blue_side[6]=='y' && red_side[8]=='b' && yellow_side[0]=='o')||
  (blue_side[6]=='y' && red_side[8]=='o' && yellow_side[0]=='b')
  )
  return 1;

else if((green_side [8]=='b' && red_side[6]=='o' && yellow_side[6]=='y')||
  (green_side [8]=='b' && red_side[6]=='y' && yellow_side[6]=='o')||
  (green_side [8]=='o' && red_side[6]=='b' && yellow_side[6]=='y')||
  (green_side [8]=='o' && red_side[6]=='y' && yellow_side[6]=='b')||
  (green_side [8]=='y' && red_side[6]=='b' && yellow_side[6]=='o')||
  (green_side [8]=='y' && red_side[6]=='o' && yellow_side[6]=='b')
  )
  
  return 2;
 else if((green_side [6]=='b' && orange_side[8]=='o' && yellow_side[8]=='y')||
  (green_side [6]=='b' && orange_side[8]=='y' && yellow_side[8]=='o')||
  (green_side [6]=='o' && orange_side[8]=='b' && yellow_side[8]=='y')||
  (green_side [6]=='o' && orange_side[8]=='y' && yellow_side[8]=='b')||
  (green_side [6]=='y' && orange_side[8]=='b' && yellow_side[8]=='o')||
  (green_side [6]=='y' && orange_side[8]=='o' && yellow_side[8]=='b')
  )

  return 3;

 else return 0;
  
}

int F2Ledges_B_O(){

  if((blue_side[3]=='o' && red_side[5]=='b')||     //b r
          (blue_side[3]=='b' && red_side[5]=='o'))
          return 1;

  else if((green_side[5]=='o' && red_side[3]=='b')||     //r g
          (green_side[5]=='b' && red_side[3]=='o'))        
          return 2;
          
  else if((green_side[3]=='o' && orange_side[5]=='b')||     //g o
          (green_side[3]=='b' && orange_side[5]=='o'))         
          return 3;
   else   return 0;
  
  
  }

int j=1;
void cube_decide_F2L_BLUE_ORANGE() {
  Serial.println();
  Serial.print("F2L_BLUE_ORANGE: ");
  Serial.println();
  if (solve_stage == 4 &&
     blue_side[5] == 'b' && blue_side[8] == 'b' &&  orange_side[3] == 'o' && orange_side[6] == 'o'&& yellow_side[2] == 'y')
  {  print_whole_cube();
    Serial.print(" F2L_BLUE_ORANGE was Solved.");
    solve_stage = 5;
  }
  else if (solve_stage == 4) {

 int BOY=BOYcorner();
   
 
 while(j<2){
  j++;
  if (BOY==1) {left_inverted();back_inverted();left();}
  else if(BOY==2){left();back();back();left_inverted();}
  else if(BOY==3){down();back();down_inverted();}
  delay(300);
  int RBedges=F2Ledges_B_O();
  if (RBedges==1){back_inverted();left_inverted();back();left();back();up();back_inverted();up_inverted();}//b r
  else if(RBedges==2){back_inverted();down_inverted();back();down();back();left();back_inverted();left_inverted();}//r g
  else if(RBedges==3){back();down();back_inverted();down_inverted();back_inverted();right_inverted();back();right();}//g o
  delay(300);
 }
 


    ///////Blue_Orange corner///////
    if (blue_side[5] == 'b' && blue_side[8] == 'b' &&  orange_side[3] == 'o' && orange_side[6] == 'o')  Serial.print(" B O was Solved.");
    else {
      if (white_side[8] == 'o' && white_side[1] == 'b' && green_side[1] == 'o' && orange_side[0] == 'y' && blue_side[2] == 'b') {
        right();
        back();
        right_inverted();
      }
      else if (white_side[8] == 'b' && white_side[3] == 'o' && orange_side[0] == 'o' && blue_side[2] == 'y' && red_side[1] == 'b') {
        up_inverted();
        back_inverted();
        up();
      }
      else if (white_side[8] == 'o' && white_side[7] == 'o' && blue_side[2] == 'b' && blue_side[1] == 'b' && orange_side[2] == 'y') {
        back_inverted();
        up_inverted();
        back();
        up();
      }
      else if (white_side[8] == 'b' && white_side[5] == 'b' && orange_side[0] == 'o' && orange_side[1] == 'o' && blue_side[2] == 'y') {
        back();
        right();
        back_inverted();
        right_inverted();
      }
      else if (white_side[7] == 'o' && blue_side[1] == 'b' && blue_side[8] == 'b' && orange_side[6] == 'o' && yellow_side[2] == 'y') {
        back();
        right();
        back_inverted();
        right_inverted();
        back_inverted();
        up_inverted();
        back();
        up();
      }
      else if (white_side[5] == 'b' && blue_side[8] == 'b' && orange_side[6] == 'o' && orange_side[1] == 'o' && yellow_side[2] == 'y') {
        back_inverted();
        up_inverted();
        back();
        up();
        back();
        right();
        back_inverted();
        right_inverted();
      }
      else if (white_side[7] == 'o' && blue_side[1] == 'b' && blue_side[8] == 'o' && orange_side[6] == 'y' && yellow_side[2] == 'b') {
        up_inverted();
        back();
        up();
        back_inverted();
        up_inverted();
        back();
        up();
      }
      else if (white_side[5] == 'b' && blue_side[8] == 'o' && orange_side[1] == 'o' && orange_side[6] == 'y' && yellow_side[2] == 'b') {
        right();
        back();
        right_inverted();
        back_inverted();
        right();
        up();
        right_inverted();
      }
      else if (white_side[5] == 'b' && blue_side[8] == 'y' && orange_side[6] == 'b' && orange_side[1] == 'o' && yellow_side[2] == 'o') {
        right();
        back_inverted();
        right_inverted();
        back();
        right();
        back_inverted();
        right_inverted();
      }
      else if (white_side[7] == 'o' && blue_side[1] == 'b' && blue_side[8] == 'y' && orange_side[6] == 'b' && yellow_side[2] == 'o') {
        up_inverted();
        back_inverted();
        up();
        back();
        up_inverted();
        back_inverted();
        up();
      }
      else if (white_side[8] == 'y' && blue_side[2] == 'o' && blue_side[5] == 'b' && orange_side[0] == 'b' && orange_side[3] == 'o') {
        right();
        back();
        right_inverted();
        back_inverted();
        right();
        back();
        right_inverted();
        back_inverted();
        right();
        back();
        right_inverted();
      }
      else if (white_side[8] == 'y' && blue_side[2] == 'o' && blue_side[5] == 'o' && orange_side[0] == 'b' && orange_side[3] == 'b') {
        right();
        back_inverted();
        right_inverted();
        back();
        up_inverted();
        back();
        up();
      }
      else if (white_side[8] == 'o' && blue_side[2] == 'b' && blue_side[5] == 'b' && orange_side[0] == 'y' && orange_side[3] == 'o') {
        back();
        up_inverted();
        back();
        up();
        back();
        up_inverted();
        back();
        up();
        up();
      }
      else if (white_side[8] == 'o' && blue_side[2] == 'b' && blue_side[5] == 'o' && orange_side[0] == 'y' && orange_side[3] == 'b') {
        back();
        up_inverted();
        back_inverted();
        up();
        back_inverted();
        right();
        back();
        right_inverted();
      }
      else if (white_side[8] == 'b' && blue_side[2] == 'y' && blue_side[5] == 'b' && orange_side[0] == 'o' && orange_side[3] == 'o') {
        back_inverted();
        right();
        back_inverted();
        right_inverted();
        back_inverted();
        right();
        back();
        back();
        right_inverted();
      }
      else if (white_side[8] == 'b' && blue_side[2] == 'y' && blue_side[5] == 'o' && orange_side[0] == 'o' && orange_side[3] == 'b') {
        back_inverted();
        right();
        back();
        right_inverted();
        back();
        up_inverted();
        back_inverted();
        up();
      }
      else if (white_side[8] == 'o' && white_side[5] == 'o' && blue_side[2] == 'b' && orange_side[0] == 'y' && orange_side[1] == 'b') {
        right();
        back_inverted();
        right_inverted();
        back();
        back();
        up_inverted();
        back_inverted();
        up();
      }
      else if (white_side[7] == 'b' && white_side[8] == 'b' && blue_side[1] == 'o' && blue_side[2] == 'y' && orange_side[0] == 'o') {
        up_inverted();
        back();
        up();
        back();
        back();
        right();
        back();
        right_inverted();
      }
      else if (white_side[8] == 'o' && white_side[1] == 'o' && blue_side[2] == 'b' && orange_side[0] == 'y' && green_side[1] == 'b') {
        back();
        up_inverted();
        back();
        back();
        up();
        back();
        up_inverted();
        back();
        back();
        up();
      }
      else if (white_side[8] == 'b' && white_side[3] == 'b' && blue_side[2] == 'y' && orange_side[0] == 'o' && red_side[1] == 'o') {
        back_inverted();
        right();
        back();
        back();
        right_inverted();
        back_inverted();
        right();
        back();
        back();
        right_inverted();
      }
      else if (white_side[8] == 'o' && white_side[3] == 'o' && blue_side[2] == 'b' && orange_side[0] == 'y' && red_side[1] == 'b') {
       back();
        up_inverted();
        back_inverted();
        up();
        back();
        up_inverted();
        back();
        back();
        up();
       
        
      }
      else if (white_side[8] == 'b' && white_side[1] == 'b' && blue_side[2] == 'y' && orange_side[0] == 'o' && green_side[1] == 'o') {
        back_inverted();
        right();
        back();
        right_inverted();
        back_inverted();
        right();
        back();
        back();
        right_inverted();
      }
      else if (white_side[8] == 'o' && white_side[5] == 'b' && blue_side[2] == 'b' && orange_side[0] == 'y' && orange_side[1] == 'o') {
        back_inverted();
        right();
        back_inverted();
        right_inverted();
        back();
        right();
        back();
        right_inverted();
      }
      else if (white_side[7] == 'o' && white_side[8] == 'b' && blue_side[1] == 'b' && blue_side[2] == 'y' && orange_side[0] == 'o') {
        back();
        up_inverted();
        back();
        up();
        back_inverted();
        up_inverted();
        back_inverted();
        up();
      }
      else if (white_side[8] == 'o' && white_side[3] == 'b' && blue_side[2] == 'b' && orange_side[0] == 'y' && red_side[1] == 'o') {
        back_inverted();
        right();
        back();
        right_inverted();
        back();
        right();
        back();
        right_inverted();
      }
      else if (white_side[8] == 'b' && white_side[1] == 'o' && blue_side[2] == 'y' && orange_side[2] == 'o' && green_side[1] == 'b') {
        back();
        up_inverted();
        back_inverted();
        up();
        back_inverted();
        up_inverted();
        back_inverted();
        up();
      }
      else if (white_side[7] == 'b' && white_side[8] == 'o' && blue_side[1] == 'o' && blue_side[2] == 'b' && orange_side[0] == 'y') {
        back();
        up_inverted();
        back();
        back();
        up();
        back_inverted();
        right();
        back();
        right_inverted();
      }
      else if (white_side[8] == 'b' && white_side[5] == 'o' && blue_side[2] == 'y' && orange_side[0] == 'o' && orange_side[1] == 'b') {
        back_inverted();
        right();
        back();
        back();
        right_inverted();
        back();
        up_inverted();
        back_inverted();
        up();
      }
      else if (white_side[7] == 'b' && white_side[8] == 'y' && blue_side[1] == 'o' && blue_side[2] == 'o' && orange_side[0] == 'b') {
        right();
        back();
        right_inverted();
        back();
        back();
        right();
        back();
        right_inverted();
        back_inverted();
        right();
        back();
        right_inverted();
      }
      else if (white_side[8] == 'y' && white_side[5] == 'o' && blue_side[2] == 'o' && orange_side[0] == 'b' && orange_side[1] == 'b') {
        up_inverted();
        back_inverted();
        up();
        back();
        back();
        up_inverted();
        back_inverted();
        up();
        back();
        up_inverted();
        back_inverted();
        up();
      }
      else if (white_side[8] == 'y' && white_side[3] == 'b' && blue_side[2] == 'o' && orange_side[0] == 'b' && red_side[1] == 'o') {
        back();
        back();
        right();
        back();
        right_inverted();
        back();
        right();
        back_inverted();
        right_inverted();
      }
      else if (white_side[8] == 'y' && white_side[1] == 'o' && blue_side[2] == 'o' && orange_side[0] == 'b' && green_side[1] == 'b') {
        back();
        back();
        up_inverted();
        back_inverted();
        up();
        back_inverted();
        up_inverted();
        back();
        up();
      }
      else if (white_side[8] == 'y' && white_side[1] == 'b' && blue_side[2] == 'o' && orange_side[0] == 'b' && green_side[1] == 'o') {
        back();
        right();
        back();
        back();
        right_inverted();
        back();
        right();
        back_inverted();
        right_inverted();
      }
      else if (white_side[8] == 'y' && white_side[3] == 'o' && blue_side[2] == 'o' && orange_side[0] == 'b' && red_side[1] == 'b') {
        back_inverted();
        up_inverted();
        back();
        back();
        up();
        back_inverted();
        up_inverted();
        back();
        up();
      }
      else if (white_side[8] == 'y' && white_side[5] == 'b' && blue_side[2] == 'o' && orange_side[0] == 'b' && orange_side[1] == 'o') {
        right();
        back();
        back();
        right_inverted();
        back_inverted();
        right();
        back();
        right_inverted();
      }
      else if (white_side[7] == 'o' && white_side[8] == 'y' && blue_side[1] == 'b' && blue_side[2] == 'o' && orange_side[0] == 'b') {
        up_inverted();
        back();
        back();
        up();
        back();
        up_inverted();
        back_inverted();
        up();
      }
      else if (blue_side[5] == 'o' && blue_side[8] == 'b' && orange_side[3] == 'b' && orange_side[6] == 'o' && yellow_side[2] == 'y') {
        right();
        back_inverted();
        right_inverted();
        back();
        up_inverted();
        back();
        back();
        up();
        back();
        up_inverted();
        back();
        back();
        up();
      }
      else if (blue_side[5] == 'b' && blue_side[8] == 'o' && orange_side[3] == 'o' && orange_side[6] == 'y' && yellow_side[2] == 'b') {
        right();
        back_inverted();
        right_inverted();
        back();
        right();
        back();
        back();
        right_inverted();
        back();
        right();
        back_inverted();
        right_inverted();
      }
      else if (blue_side[5] == 'b' && blue_side[8] == 'y' && orange_side[3] == 'o' && orange_side[6] == 'b' && yellow_side[2] == 'o') {
        right();
        back_inverted();
        right_inverted();
        back_inverted();
        right();
        back();
        right_inverted();
        back_inverted();
        right();
        back();
        back();
        right_inverted();
      }
      else if (blue_side[5] == 'o' && blue_side[8] == 'o' && orange_side[3] == 'b' && orange_side[6] == 'y' && yellow_side[2] == 'b') {
        right();
        back();
        right_inverted();
        back_inverted();
        right();
        back_inverted();
        right_inverted();
        back();
        back();
        up_inverted();
        back_inverted();
        up();
      }
      else if (blue_side[5] == 'o' && blue_side[8] == 'y' && orange_side[3] == 'b' && orange_side[6] == 'b' && yellow_side[2] == 'o') {
        right();
        back_inverted();
        right_inverted();
        back();
        up_inverted();
        back_inverted();
        up();
        back_inverted();
        up_inverted();
        back_inverted();
        up();
      }
      else  {
       if(blue_side[5] != 'b' || blue_side[8] != 'b' || orange_side[3] != 'o' || orange_side[6] != 'o' || yellow_side[2] != 'y'){
        Serial.println("error in O B");
        back();
        }
        
      }
    }
  }
  
    delay(300);

}







///////////F2L_REEEEEd_GREEEEEEEEEEEEN /////////////

int RGYcorner(){              ///finding the BLUE_ORANGE_YELLOW corner
if((blue_side[6]=='r' && red_side[8]=='g' && yellow_side[0]=='y')||
  (blue_side[6]=='r' && red_side[8]=='y' && yellow_side[0]=='g')||
  (blue_side[6]=='g' && red_side[8]=='r' && yellow_side[0]=='y')||
  (blue_side[6]=='g' && red_side[8]=='y' && yellow_side[0]=='r')||
  (blue_side[6]=='y' && red_side[8]=='r' && yellow_side[0]=='g')||
  (blue_side[6]=='y' && red_side[8]=='g' && yellow_side[0]=='r')
  )
  return 1;

else if((blue_side [8]=='r' && orange_side[6]=='g' && yellow_side[2]=='y')||
  (blue_side [8]=='r' && orange_side[6]=='y' && yellow_side[2]=='g')||
  (blue_side [8]=='g' && orange_side[6]=='r' && yellow_side[2]=='y')||
  (blue_side [8]=='g' && orange_side[6]=='y' && yellow_side[2]=='r')||
  (blue_side [8]=='y' && orange_side[6]=='r' && yellow_side[2]=='g')||
  (blue_side [8]=='y' && orange_side[6]=='g' && yellow_side[2]=='r')
  )
  
  return 2;
 else if((green_side [6]=='r' && orange_side[8]=='g' && yellow_side[8]=='y')||
  (green_side [6]=='r' && orange_side[8]=='y' && yellow_side[8]=='g')||
  (green_side [6]=='g' && orange_side[8]=='r' && yellow_side[8]=='y')||
  (green_side [6]=='g' && orange_side[8]=='y' && yellow_side[8]=='r')||
  (green_side [6]=='y' && orange_side[8]=='r' && yellow_side[8]=='g')||
  (green_side [6]=='y' && orange_side[8]=='g' && yellow_side[8]=='r')
  )

  return 3;

 else return 0;
  
}

int F2Ledges_R_G(){

  if((blue_side[3]=='r' && red_side[5]=='g')||     //b r
          (blue_side[3]=='g' && red_side[5]=='r'))
          return 1;

  else if((blue_side[5]=='r' && orange_side[3]=='g')||     //b o
          (blue_side[5]=='g' && orange_side[3]=='r'))        
          return 2;
          
  else if((green_side[3]=='r' && orange_side[5]=='g')||     //g o
          (green_side[3]=='g' && orange_side[5]=='r'))         
          return 3;
   else   return 0;
  
  
  }

int x=0;
void cube_decide_F2L_RED_GREEN() {
  Serial.println();
  Serial.print("F2L_RED_GREEN: ");
  Serial.println();
  if (solve_stage == 5 &&
     yellow_side[6] == 'y' && red_side[3] == 'r' && red_side[6] == 'r' && green_side[8] == 'g' && green_side[5] == 'g')
  {  print_whole_cube();
    Serial.print(" F2L_RED_GREEN was Solved.");
    solve_stage = 6;
  }
  else if (solve_stage == 5) {

    int RGY=RGYcorner();
 
 while(x<2){
  x++;
  if (RGY==1) {left_inverted();back();left();}
  else if(RGY==2){right();back();back();right_inverted();}
  else if(RGY==3){right_inverted();back_inverted();right();}
  delay(3000);
  int RGedges=F2Ledges_R_G();
  if (RGedges==1){back_inverted();left_inverted();back();left();back();up();back_inverted();up_inverted();}//b r
  else if(RGedges==2){back();right();back_inverted();right_inverted();back_inverted();up_inverted();back();up();}//b o
  else if(RGedges==3){back();down();back_inverted();down_inverted();back_inverted();right_inverted();back();right();}//g o
  
  delay(200);
 }
 


    ////////////////////Red_Green Corner///////////////////////

    if ( green_side[2] == 'g' && red_side[0] == 'y' && blue_side[1] == 'r' && white_side[0] == 'r' && white_side[7] == 'g') {
      left(); back(); left_inverted();
    } else if (green_side[2] == 'y' && orange_side[1] == 'g' && white_side[5] == 'r' && white_side[0] == 'g' && red_side[0] == 'r' ) {
      down_inverted(); back_inverted(); down();
    } else if (green_side[2] == 'g' && green_side[7] == 'g' && red_side[0] == 'y' && white_side[0] == 'r' && white_side[1] == 'r' ) {
      back_inverted (); down_inverted(); back(); down();
    } else if (red_side[0] == 'r' && red_side[1] == 'r' && white_side[0] == 'g' && white_side[3] == 'g' && green_side[2] == 'y') {
      back(); left(); back_inverted(); left_inverted();
    } else if (green_side[8] == 'g' && green_side[1] == 'g' && red_side[6] == 'r' && white_side[1] == 'r' && yellow_side[6] == 'y') {
      back(); left(); back_inverted(); left_inverted(); back_inverted(); down_inverted(); back(); down();
    } else if (yellow_side[0] == 'y' && red_side[6] == 'r' && red_side[1] == 'r' && white_side[3] == 'g' && green_side[8] == 'g') {
      back_inverted (); down_inverted(); back(); down(); back(); left(); back_inverted(); left_inverted();
    } else if (yellow_side[6] == 'g' && red_side[6] == 'g' && white_side[1] == 'r' && green_side[1] == 'g' && green_side[8] == 'r') {
      down_inverted(); back (); down(); back_inverted(); down_inverted(); back(); down();
    } else if (yellow_side[6] == 'g' && red_side[1] == 'r' && red_side[6] == 'y' && white_side[3] == 'g' && green_side[8] == 'r') {
      left(); back(); left_inverted(); back_inverted(); left();  back_inverted(); left();
    } else if (yellow_side[6] == 'r' && red_side[1] == 'r' && red_side[6] == 'g' && white_side[3] == 'g' && green_side[8] == 'y' ) {
      left(); back_inverted(); left_inverted(); back(); left(); back_inverted(); left_inverted();
    } else if (yellow_side[6] == 'r' && red_side[6] == 'g' && white_side[1] == 'r' && green_side[1] == 'g' && green_side[8] == 'y' ) {
      down_inverted(); back_inverted(); down(); back(); down_inverted(); back_inverted(); down();
    } else if (green_side[5] == 'g' && green_side[2] == 'r' && red_side[3] == 'r' && red_side[0] == 'g' && white_side[0] == 'y') {
      left(); back(); left_inverted(); back_inverted(); left();  back(); left_inverted(); back_inverted(); left();  back(); left_inverted();
    } else if (red_side[0] == 'g' && red_side[3] == 'g' && white_side[0] == 'y' && green_side[2] == 'r' && green_side[5] == 'r') {
      left(); back_inverted(); left_inverted(); back(); down_inverted(); back(); down();
    } else if (red_side[3] == 'r' && red_side[0] == 'y' && white_side[0] == 'r' && green_side[2] == 'g' && green_side[5] == 'g' ) {
      back(); down_inverted(); back(); down(); back(); down_inverted(); back(); back(); down();
    } else if (red_side[3] == 'g' && red_side[0] == 'y' && white_side[0] == 'r' && green_side[2] == 'g' && green_side[5] == 'r') {///////////
      back(); down_inverted(); back_inverted(); down(); back_inverted(); left();  back(); left_inverted();
    } else if (red_side[0] == 'r' && red_side[3] == 'r' && white_side[0] == 'g' && green_side[5] == 'g' && green_side[2] == 'y') {
      back_inverted(); left(); back_inverted(); left_inverted();  back_inverted(); left(); back(); back(); left_inverted();
    } else if (red_side[0] == 'r' && red_side[3] == 'g' && white_side[0] == 'g' && green_side[5] == 'r' && green_side[2] == 'y') {
      back_inverted(); left();  back(); left_inverted();  back(); down_inverted(); back_inverted(); down();
    } else if (red_side[1] == 'g' && red_side[0] == 'y' && white_side[0] == 'r' && white_side[3] == 'r' && green_side[2] == 'g' ) {
      left(); back_inverted(); left_inverted(); back(); back();  down_inverted(); back_inverted(); down();
    } else if (red_side[0] == 'r' && white_side[0] == 'g' && white_side[1] == 'g' && green_side[1] == 'r' && green_side[2] == 'y' ) {
      down_inverted(); back(); down(); back(); back(); left(); back(); left_inverted();
    } else if (blue_side[1] == 'g' && red_side[0] == 'y' && white_side[7] == 'r' && white_side[0] == 'r' && green_side[2] == 'g' ) {
      back(); down_inverted(); back(); back(); down(); back(); down_inverted(); back(); back(); down();
    } else if (red_side[0] == 'r' && white_side[5] == 'g' && white_side[0] == 'g' && green_side[2] == 'y' && orange_side[1] == 'r') {
      back_inverted(); left(); back(); back();  left_inverted();  back_inverted(); left() ; back(); back(); left_inverted();
    } else if (red_side[0] == 'y' && white_side[0] == 'r' && white_side[5] == 'r' && orange_side[1] == 'g' && green_side[2] == 'g') {
      back(); down_inverted(); back_inverted(); down() ; back(); down_inverted(); back(); back(); down();
    } else if (red_side[0] == 'r' && white_side[0] == 'g' && white_side[7] == 'g' && blue_side[1] == 'r' && green_side[2] == 'y') {
      back_inverted(); left();  back(); left_inverted(); back_inverted(); left();  back(); back(); left_inverted();
    } else if (red_side[1] == 'r' && red_side[0] == 'y' && white_side[0] == 'r' && white_side[3] == 'g' && green_side[2] == 'g') {
      back_inverted(); left();  back_inverted(); left_inverted(); back(); left(); back(); left_inverted();
    } else if (red_side[0] == 'r' && white_side[1] == 'w' && white_side[0] == 'g' && green_side[1] == 'g' && green_side[2] == 'y' ) {
      back(); down_inverted(); back(); down(); back_inverted(); down_inverted(); back_inverted(); down();
    } else if (red_side[0] == 'y' && white_side[0] == 'r' && white_side[5] == 'g' && orange_side[1] == 'r' && green_side[2] == 'g' ) {
      back_inverted(); left();  back(); left_inverted(); back(); left(); back(); left_inverted();
    } else if (red_side[0] == 'r' && white_side[7] == 'r' && white_side[0] == 'g' && blue_side[1] == 'g' && green_side[2] == 'y' ) {
      back(); down_inverted(); back_inverted(); down(); back_inverted(); down_inverted(); back_inverted(); down();
    } else if (red_side[0] == 'y' && white_side[0] == 'r' && white_side[1] == 'g' && green_side[2] == 'g' && green_side[1] == 'r' ) {
      back(); down_inverted(); back(); back(); down();  back_inverted(); left(); back(); left_inverted();
    } else if (red_side[0] == 'r' && red_side[1] == 'g' && white_side[0] == 'g' && white_side[3] == 'r' && green_side[2] == 'y') {
      back(); left();  back(); back(); left_inverted(); back(); down_inverted(); back_inverted(); down();
    } else if (red_side[0] == 'g' && white_side[0] == 'y' && white_side[1] == 'g' && green_side[1] == 'r' && green_side[2] == 'r') {
      left();  back(); left_inverted();  back(); back(); left();  back(); left_inverted(); back_inverted();  left();  back(); left_inverted();
    } else if (red_side[0] == 'g' && red_side[1] == 'g' && white_side[3] == 'r' && white_side[0] == 'y' && green_side[2] == 'r' ) {
      down_inverted(); back_inverted(); down(); back(); back(); down_inverted(); back_inverted(); down(); back(); down_inverted(); back_inverted(); down();
    } else if (red_side[0] == 'g' && white_side[0] == 'y' && white_side[5] == 'g' && orange_side[1] == 'r' && green_side[2] == 'r' ) {
      back(); back(); left();  back();  left_inverted();  back(); left(); back_inverted(); left_inverted();
    } else if (red_side[0] == 'g' && white_side[0] == 'y' && white_side[7] == 'r' && blue_side[1] == 'g' && green_side[2] == 'r') {
      back(); back(); down_inverted(); back_inverted(); down(); back_inverted(); down_inverted(); back(); down();
    } else if (red_side[0] == 'g' && white_side[0] == 'y' && white_side[7] == 'g' && blue_side[1] == 'r' && green_side[2] == 'r') {
      back(); left();  back(); back(); left_inverted(); back(); left(); back_inverted(); left_inverted();
    } else if (red_side[0] == 'g' && white_side[0] == 'y' && white_side[5] == 'r' && orange_side[1] == 'g' && green_side[2] == 'r') {
      back_inverted(); down_inverted(); back(); back(); down(); back_inverted(); down_inverted(); back(); down();
    } else if (red_side[0] == 'g' && red_side[1] == 'r' && white_side[0] == 'y' && white_side[3] == 'g' && green_side[2] == 'r') {
      left();  back(); back(); left_inverted(); back_inverted();  left();  back(); left_inverted();
    } else if (red_side[0] == 'g' && white_side[0] == 'y' && white_side[1] == 'r' && green_side[1] == 'g' && green_side[2] == 'r' ) {
      down_inverted(); back(); back(); down(); back(); down_inverted(); back_inverted(); down();
    } else if (yellow_side[6] == 'y' && red_side[6] == 'r' && red_side[3] == 'g' && green_side[8] == 'g' && green_side[5] == 'r') {
      left(); back_inverted(); left_inverted(); back(); down_inverted(); back(); back(); down();  back(); down_inverted(); back(); back(); down();
    } else if (yellow_side[6] == 'g' && red_side[6] == 'y' && red_side[3] == 'r' && green_side[8] == 'r' && green_side[5] == 'g' ) {
      left(); back_inverted(); left_inverted(); back(); left();  back(); back(); left_inverted(); back(); left(); back_inverted(); left_inverted();
    } else if (yellow_side[6] == 'g' && red_side[6] == 'g' && red_side[3] == 'r' && green_side[8] == 'y' && green_side[5] == 'g' ) {
      left(); back_inverted(); left_inverted(); back_inverted();  left();  back(); left_inverted(); back_inverted(); left(); back(); back(); left_inverted();
    } else if (yellow_side[6] == 'g' && red_side[6] == 'y' && red_side[3] == 'g' && green_side[5] == 'r' && green_side[8] == 'r') {
      left();  back();  left_inverted(); back_inverted();  left(); back_inverted(); left_inverted(); back(); back(); down_inverted(); back_inverted(); down();
    } else if (yellow_side[6] == 'r' && red_side[6] == 'g' && red_side[3] == 'g' && green_side[8] == 'y' && green_side[5] == 'r' ) {
      left(); back_inverted(); left_inverted(); back(); down_inverted(); back_inverted(); down(); back_inverted(); down_inverted(); back_inverted(); down();
    }
    else  {
       if (yellow_side[6] != 'y' || red_side[3] != 'r' || red_side[6] != 'r' || green_side[8] != 'g' || green_side[5] != 'g' ) {
      Serial.println("error in G R");
     // down_inverted();
      back();
     // down();
      }
     
    }
  }
 
    delay(200);

}



//////////F2L_ORANGEEEEEEEEEEE_GREEEEEEEEEEN///////////////
void cube_decide_F2L_ORANGE_GREEN() {
  Serial.println();
  Serial.print("F2L_ORANGE_GREEN: ");
  Serial.println();
  if (solve_stage == 6 &&
     yellow_side[8] == 'y' && green_side[3] == 'g' && green_side[6] == 'g' && orange_side[5] == 'o' && orange_side[8] == 'o')
  {  print_whole_cube();
    Serial.print(" F2L_ORANGE_GREEN was Solved.");
    solve_stage = 7;
  }
  else if (solve_stage == 6) {


 //////////Orange_Green corner////////////////
    if (white_side[7] == 'g' && white_side[2] == 'o' && blue_side[1] == 'o' && green_side[0] == 'g' && orange_side[2] == 'y') {
      right_inverted();
      back_inverted();
      right();
    }
    else if (white_side[3] == 'o' && white_side[2] == 'g' && orange_side[2] == 'o' && green_side[0] == 'y' && red_side[1] == 'g') {
      down();
      back();
      down_inverted();
    }
    else if ( orange_side[2] == 'y' && green_side[1] == 'g' && green_side[0] == 'g' && white_side[1] == 'o' && white_side[2] == 'o') {
      back();
      down();
      back_inverted();
      down_inverted();
    }
    else if (orange_side[1] == 'o' && orange_side[1] == 'o' && green_side[0] == 'y' && white_side[5] == 'g' && white_side[2] == 'g') {
      back_inverted();
      right_inverted();
      back();
      right();
    }
    else if (orange_side[8] == 'o' && green_side[1] == 'g' && green_side[6] == 'g' && yellow_side[8] == 'y' && white_side[1] == 'o') {
      back_inverted();
      right_inverted();
      back();
      right();
      back();
      down();
      back_inverted();
      down_inverted();
    }
    else if (orange_side[8] == 'o' && orange_side[1] == 'o' && green_side[6] == 'g' && white_side[5] == 'g' && yellow_side[8] == 'y') {
      back();
      down();
      back_inverted();
      down_inverted();
      back_inverted();
      right_inverted();
      back();
      right();
    }
    else if (white_side[1] == 'o' && green_side[1] == 'g' && green_side[0] == 'o' && yellow_side[8] == 'g' && orange_side[8] == 'y') {
      down();
      back_inverted();
      down_inverted();
      back();
      down();
      back_inverted();
      down_inverted();
    }
    else if ( white_side[5] == 'g' && green_side[6] == 'o' && yellow_side[8] == 'g' && orange_side[1] == 'o' && orange_side[8] == 'y') {
      right_inverted();
      back_inverted();
      right();
      back();
      right_inverted();
      back_inverted();
      right();
    }
    else if ( white_side[5] == 'g' && yellow_side[8] == 'o' && green_side[6] == 'y' && orange_side[8] == 'g' && orange_side[1] == 'o') {
      right_inverted();
      back();
      right();
      back_inverted();
      right_inverted();
      back();
      right();
    }
    else if ( white_side[1] == 'o' && yellow_side[8] == 'o' && green_side[1] == 'g' && green_side[0] == 'y' &&  orange_side[8] == 'g') {
      down();
      back();
      down_inverted();
      back_inverted();
      down();
      back();
      down_inverted();
    }
    else if (white_side[2] == 'y' && green_side[0] == 'o' && green_side[3] == 'g' && orange_side[2] == 'g' && orange_side[5] == 'o' ) {
      right_inverted();
      back_inverted();
      right();
      back();
      right_inverted();
      back_inverted();
      right();
      back();
      right_inverted();
      back_inverted();
      right();
    }
    else if (white_side[2] == 'o' && green_side[0] == 'g' && green_side[3] == 'g' && orange_side[5] == 'o' && orange_side[2] == 'y') {
      back_inverted();
      down();
      back_inverted();
      down_inverted();
      back_inverted();
      down();
      back();
      back();
      down_inverted();
    }
    else if ( white_side[2] == 'g' && green_side[3] == 'g' && green_side[0] == 'y' && orange_side[2] == 'o' && orange_side[5] == 'o' ) {
      back();
      right_inverted();
      back();
      right();
      back();
      right_inverted();
      back();
      back();
      right();
    }
    else if ( white_side[1] == 'g' && white_side[2] == 'y' && green_side[0] == 'o' && green_side[1] == 'o' && orange_side[2] == 'g' ) {
      right_inverted();
      back_inverted();
      right();
      back();
      back();
      right_inverted();
      back_inverted();
      right();
      back();
      right_inverted();
      back_inverted();
      right();
    }
    else if ( white_side[5] == 'g' && white_side[2] == 'y' && green_side[0] == 'o' && orange_side[2] == 'g' && orange_side[1] == 'o' ) {
      right_inverted();
      back();
      back();
      right();
      back();
      right_inverted();
      back_inverted();
      right();
    }
    else if (white_side[1] == 'o' && white_side[2] == 'y' && green_side[1] == 'g' && green_side[0] == 'o' && orange_side[2] == 'g' ) {
      down();
      back();
      back();
      right();
      back();
      right_inverted();
      back_inverted();
      right();
    }
    else if (green_side[3] == 'g' && green_side[6] == 'o' && yellow_side[8] == 'g' && orange_side[5] == 'o' && orange_side[8] == 'y' ) {
      right_inverted();
      back();
      right();
      back_inverted();
      right_inverted();
      back();
      back();
      right();
      back_inverted();
      right_inverted();
    }
    else if ( green_side[3] == 'g' && green_side[6] == 'y' && yellow_side[8] == 'o' && orange_side[5] == 'o' && orange_side[8] == 'g' ) {
      right_inverted();
      back();
      right();
      back();
      right_inverted();
      back_inverted();
      right();
      back();
      right_inverted();
      back();
      back();
    }
    else if ( white_side[7] == 'o' && white_side[2] == 'o' && green_side[0] == 'g' && blue_side[1] == 'g' && orange_side[2] == 'y' ) {
      back_inverted();
      down();
      back();
      back();
      down_inverted();
      back_inverted();
      down();
      back();
      back();
      down_inverted();
    }
    else if (white_side[3] == 'g' && white_side[2] == 'g' && green_side[0] == 'y' && red_side[1] == 'o' && orange_side[2] == 'o' ) {
      back();
      right_inverted();
      back();
      back();
      right();
      back();
      right_inverted();
      back();
      back();
      right();
    }
    else if (white_side[3] == 'o' && white_side[2] == 'o' && green_side[0] == 'g' && red_side[1] == 'g' && orange_side[2] == 'y') {
      back_inverted();
      down();
      back();
      down_inverted();
      back_inverted();
      down();
      back();
      back();
      down_inverted();
    }
    else if (white_side[7] == 'g' && white_side[2] == 'g' && green_side[0] == 'y' && blue_side[1] == 'o' && orange_side[2] == 'o') {
      back();
      right_inverted();
      back_inverted();
      right();
      back_inverted();
      right_inverted();
      back();
      back();
      right();
    }
    else if (white_side[5] == 'g' && white_side[2] == 'o' && green_side[0] == 'g' && orange_side[2] == 'y' && orange_side[1] == 'o') {
      back();
      right_inverted();
      back();
      right();
      back_inverted();
      right_inverted();
      back_inverted();
      right();
    }
    else if (white_side[1] == 'o' && white_side[2] == 'g' && green_side[0] == 'y' && green_side[1] == 'g' &&  orange_side[2] == 'o') {
      back_inverted();
      down();
      back_inverted();
      down_inverted();
      back();
      down();
      back();
      down_inverted();
    }
    else if (white_side[3] == 'g' && white_side[2] == 'o' && green_side[0] == 'g' && red_side[1] == 'o' && orange_side[2] == 'y') {
      back();
      right_inverted();
      back_inverted();
      right();
      back_inverted();
      right_inverted();
      back_inverted();
      right();
    }
    else if (white_side[7] == 'o' && white_side[2] == 'g' && green_side[0] == 'y' && blue_side[1] == 'g' && orange_side[2] == 'o') {
      back_inverted();
      down();
      back();
      down_inverted();
      back();
      down();
      back();
      down_inverted();
    }
    else if (white_side[1] == 'g' && white_side[2] == 'o' && green_side[1] == 'o' && green_side[0] == 'g' && orange_side[2] == 'y') {
      back_inverted();
      down();
      back();
      back();
      down_inverted();
      back();
      right_inverted();
      back_inverted();
      right();
    }
    else if (white_side[5] == 'o' && white_side[2] == 'g' && green_side[0] == 'y' && orange_side[1] == 'g' && orange_side[2] == 'o') {
      back();
      right_inverted();
      back();
      back();
      right();
      back_inverted();
      down();
      back();
      down_inverted();
    }
    else if (white_side[3] == 'g' && white_side[2] == 'y' && red_side[1] == 'o' && green_side[0] == 'o' && orange_side[2] == 'g') {
      back();
      back();
      right_inverted();
      back_inverted();
      right();
      back_inverted();
      right_inverted();
      back();
      right();
    }
    else if (white_side[7] == 'o' && white_side[2] == 'y' && blue_side[1] == 'g' && green_side[0] == 'o' && orange_side[2] == 'g') {
      back();
      back();
      down();
      back();
      down_inverted();
      back();
      down();
      back_inverted();
      down_inverted();
    }
    else if (white_side[7] == 'g' && white_side[8] == 'y' && blue_side[1] == 'o' && green_side[0] == 'o' && orange_side[2] == 'g') {
      back_inverted();
      right_inverted();
      back();
      back();
      right();
      back_inverted();
      right_inverted();
      back();
      right();
    }
    else if (white_side[3] == 'o' && white_side[2] == 'y' && red_side[1] == 'g' && green_side[0] == 'o' && orange_side[2] == 'g') {
      back();
      down();
      back();
      back();
      down();
      back_inverted();
      down();
      back_inverted();
      down_inverted();
    }
    else if (white_side[2] == 'y' && green_side[0] == 'o' && green_side[3] == 'o' && orange_side[2] == 'g' && orange_side[5] == 'g') {
      right_inverted();
      back();
      right();
      back_inverted();
      down();
      back_inverted();
      down_inverted();
    }
    else if (white_side[2] == 'o' && green_side[0] == 'g' && green_side[3] == 'o' && orange_side[2] == 'y' && orange_side[5] == 'g') {
      back_inverted();
      down();
      back();
      down_inverted();
      back();
      right_inverted();
      back_inverted();
      right();
    }
    else if (white_side[2] == 'g' && green_side[0] == 'y' && green_side[3] == 'o' && orange_side[2] == 'o' && orange_side[5] == 'g') {
      back();
      right_inverted();
      back_inverted();
      right();
      back_inverted();
      down();
      back();
      down_inverted();
    }
    else if (white_side[5] == 'o' && white_side[2] == 'o' && green_side[0] == 'g' && orange_side[1] == 'g' && orange_side[2] == 'y') {
      right_inverted();
      back();
      right();
      back();
      back();
      down();
      back();
      down_inverted();
    }
    else if (white_side[1] == 'g' && white_side[2] == 'g' && green_side[1] == 'o' && green_side[0] == 'y' && orange_side[2] == 'o') {
      down();
      back_inverted();
      down_inverted();
      back();
      back();
      right_inverted();
      back_inverted();
      right();
    }
    else if (yellow_side[8] == 'y' && green_side[3] == 'o' && green_side[6] == 'g' && orange_side[5] == 'g' && orange_side[8] == 'o') {
      right_inverted();
      back();
      right();
      back_inverted();
      down();
      back();
      back();
      down_inverted();
      back_inverted();
      down();
      back();
      back();
      down_inverted();
    }
    else if (yellow_side[8] == 'g' && green_side[3] == 'o' && green_side[6] == 'o' && orange_side[5] == 'g' && orange_side[8] == 'y') {
      right_inverted();
      back_inverted();
      right();
      back();
      right_inverted();
      back();
      right();
      back();
      back();
      down();
      back();
      down_inverted();
    }
    else if (yellow_side[8] == 'o' && green_side[3] == 'o' && green_side[6] == 'y' && orange_side[5] == 'g' && orange_side[8] == 'g') {
      right_inverted();
      back();
      right();
      back_inverted();
      down();
      back();
      down_inverted();
      back();
      down();
      back();
      down_inverted();
    }
    else if (white_side[5] == 'o' && white_side[2] == 'y' && green_side[0] == 'o' && orange_side[1] == 'g' && orange_side[2] == 'g') {
      down();
      back();
      down_inverted();
      back();
      back();
      down();
      back();
      down_inverted();
      back_inverted();
      down();
      back();
      down_inverted();
    }
    else  {
     if(yellow_side[8] != 'y' || green_side[3] != 'g' || green_side[6] != 'g' || orange_side[5] != 'o' || orange_side[8] != 'o'){
      Serial.println("error in O G");
      
     // right();
      back();
     // right_inverted();
     }
    }

  }
 
    delay(300);

}

  

void WhiteFace(){
  Serial.println();
  Serial.print("WhiteFace: ");
  Serial.println();
  if (solve_stage == 7 &&
      white_side[0] == 'w' && white_side[1] == 'w' && white_side[2] == 'w' && white_side[3] == 'w' && 
      white_side[4] == 'w' && white_side[6] == 'w' && white_side[7] == 'w' && white_side[8] == 'w' )
  {  print_whole_cube();
    Serial.print(" White Face was Solved.");
    solve_stage = 8;
  }
  else if(solve_stage==7){
  //case 1
if(white_side[1]=='w'&&white_side[5]=='w'&&white_side[4]=='w'&&white_side[7]=='w'
&&white_side[8]=='w'&&white_side[0]=='w'&&white_side[3]=='w'&&red_side[2]=='w'&&green_side[0]=='w'){

  left_inverted();down();left();up_inverted();left_inverted();down_inverted();left();up();
}
//case 2
else if(white_side[1]=='w'&&white_side[5]=='w'&&white_side[4]=='w'&&white_side[7]=='w'
&&white_side[6]=='w'&&white_side[3]=='w'&&white_side[2]=='w'&&orange_side[0]=='w'&&green_side[2]=='w'){

  down_inverted();right();down();left_inverted();down_inverted();right_inverted();down();left(); 
}
//case 3
else if(white_side[1]=='w'&&white_side[5]=='w'&&white_side[4]=='w'&&white_side[7]=='w'
&&white_side[8]=='w'&&white_side[0]=='w'&&white_side[3]=='w'&&blue_side[0]=='w'&&green_side[0]=='w'){

  right_inverted();up();right();down_inverted();right_inverted();up_inverted();right();down();
}
//case 4
else if(white_side[1]=='w'&&white_side[5]=='w'&&white_side[4]=='w'&&white_side[7]=='w'
&&white_side[6]=='w'&&white_side[3]=='w'&&white_side[2]=='w'&&blue_side[2]=='w'&&red_side[0]=='w'){

  up_inverted();left();up();right_inverted();up_inverted();left_inverted();up();right();
}
//case 5
else if(white_side[1]=='w'&&white_side[5]=='w'&&white_side[4]=='w'&&white_side[7]=='w'
&&white_side[8]=='w'&&white_side[6]=='w'&&white_side[3]=='w'&&red_side[0]=='w'&&orange_side[2]=='w'){

  down();left();up_inverted();left_inverted();down_inverted();left();up();left_inverted();
}



//case 6
else if(white_side[0]=='w'&&white_side[1]=='w'&&white_side[3]=='w'&&white_side[4]=='w'&&
white_side[5]=='w'&&white_side[6]=='w'&&white_side[7]=='w'&&green_side[0]=='w'&&blue_side[2]=='w'){

  right();down();left_inverted();down_inverted();right_inverted();down();left();down_inverted();

}
//case 7
else if(white_side[0]=='w'&&white_side[1]=='w'&&white_side[2]=='w'&&white_side[3]=='w'&&
white_side[4]=='w'&&white_side[5]=='w'&&white_side[7]=='w'&&red_side[2]=='w'&&orange_side[0]=='w'){

  up();right();down_inverted();right_inverted();up_inverted();right();down();right_inverted();

}
//case 8
else if(white_side[1]=='w'&&white_side[2]=='w'&&white_side[3]=='w'&&white_side[4]=='w'&&
white_side[5]=='w'&&white_side[7]=='w'&&white_side[8]=='w'&&green_side[2]=='w'&&blue_side[0]=='w'){

  left();up();right_inverted();up_inverted();left_inverted();up();right();up_inverted();

}
//case 9
else if(white_side[1]=='w'&&white_side[2]=='w'&&white_side[3]=='w'&&white_side[4]=='w'&&
white_side[5]=='w'&&white_side[7]=='w'&&white_side[8]=='w'&&red_side[0]=='w'&&red_side[2]=='w'){

  up();up();front();up_inverted();back();back();up();front_inverted();up_inverted();back();back();up_inverted();
  
}
//case 10
else if(white_side[1]=='w'&&white_side[3]=='w'&&white_side[4]=='w'&&white_side[5]=='w'
&&white_side[6]=='w'&&white_side[7]=='w'&&white_side[8]=='w'&&green_side[0]=='w'&&green_side[2]=='w'){
  
  left();left();front();left_inverted();back();back();left();front_inverted();left_inverted();back();back();left_inverted();
  
}




    
      // pic 11
  else if(white_side[0]=='w'&& white_side[1]=='w'&& white_side[3]=='w'&&white_side[4]=='w'&& white_side[5]=='w'
           && white_side[6]=='w' && white_side[7]=='w' && orange_side[0]=='w' && orange_side[2]=='w'){
    down();
    down();
    front();
    down_inverted();
    back();
    back();
    left();
    front_inverted();
    left_inverted();
    back();
    back();
    down_inverted();  
  }//pic 12
 else if(white_side[0]=='w'&& white_side[1]=='w'&&white_side[2]=='w'&&white_side[3]=='w'&& white_side[4]=='w'&&
          white_side[5]=='w'&& white_side[7]=='w'&& blue_side[0]=='w'&& blue_side[2]=='w'){
 right();
 right();
 front();
 right_inverted();
 back();
 back();
 right();
 front_inverted();
 right_inverted();
 back();
 back();
 right_inverted();
 } //pic 13
 else if(white_side[1]=='w'&& white_side[2]=='w'&& white_side[3]=='w'&& white_side[4]=='w'&&
          white_side[5]=='w'&& white_side[7]=='w'&& orange_side[0]=='w'&& blue_side[0]=='w'&& red_side[0]=='w'){
  up_inverted();
  back_inverted();
  up();
  back_inverted();
  up_inverted();
  back();
  back();
  up();
 } //pic 14 
 else if(white_side[1]=='w'&& white_side[3]=='w'&& white_side[4]=='w'&& white_side[5]=='w'
   && white_side[7]=='w'&& white_side[8]=='w'&& green_side[0]=='w'&& red_side[0]=='w'&& blue_side[0]=='w'){
  left_inverted();
  back_inverted();
  left();
  back_inverted();
  left_inverted();
  back();
  back();
  left(); 
 } //pic 15 
 else if(white_side[1]=='w'&& white_side[3]=='w'&& white_side[4]=='w'&& white_side[5]=='w'&&
    white_side[6]=='w'&& white_side[7]=='w'&& green_side[0]=='w'&& orange_side[0]=='w'&& red_side[0]=='w'){
  down_inverted();
  back_inverted();
  down();
  back_inverted();
  down_inverted();
  back();
  back();
  down();
 }


//16
else if (white_side[3]=='w' && white_side[0]=='w' && white_side[1]=='w' && white_side[4]=='w' && white_side[7]=='w'
&& white_side[5]=='w' && blue_side[0]=='w' && orange_side[0]=='w' && green_side[0]=='w'){
  right_inverted();
  back_inverted();
  right();
  back_inverted();
  right_inverted();
  back();
  back();
  right();
}
//17
else if (white_side[3]=='w' && white_side[0]=='w' && white_side[1]=='w' && white_side[4]=='w' && 
   white_side[7]=='w' && white_side[5]=='w' && red_side[2]=='w' && blue_side[2]=='w' && orange_side[2]=='w'){
up();
back();
up_inverted();
back();
up();
back();
back();
up_inverted();
}
//18
else if(white_side[3]=='w' && white_side[2]=='w' && white_side[1]=='w' && white_side[4]=='w' && white_side[7]=='w' &&
          white_side[5]=='w' && red_side[2]=='w' && green_side[2]=='w' && blue_side[2]=='w'){
left();
back();
left_inverted();
back();
left();
back();
back();
left_inverted();
}
//19
else if(white_side[3]=='w' && white_side[8]=='w' && white_side[1]=='w' && white_side[4]=='w' && 
       white_side[7]=='w' && white_side[5]=='w' && red_side[2]=='w' && green_side[2]=='w' && orange_side[2]=='w'){
down();
back();
down_inverted();
back();
down();
back();
back();
down_inverted();
}
//20
else if(white_side[3]=='w' && white_side[6]=='w' && white_side[1]=='w' && white_side[4]=='w' && white_side[7]=='w' 
            && white_side[5]=='w' && green_side[2]=='w' && blue_side[2]=='w' && orange_side[2]=='w'){
right();
back();
right_inverted();
back();
right();
back();
back();
right_inverted();
}


 else if (white_side[7]=='w' && white_side[3]=='w' && white_side[4]=='w' && white_side[5]=='w' && white_side[1]=='w' //21
                  && red_side[2]=='w' && green_side[2]=='w' && green_side[0]=='w' && orange_side[0]=='w' ){
  up();
  back();
  back();
  up();
  up();
  back_inverted();
  up();
  up();
  back_inverted();
  up();
  up();
  back();
  back();
  up();
}

 else if (white_side[7]=='w' && white_side[3]=='w' && white_side[4]=='w' && white_side[5]=='w' && white_side[1]=='w' && //22
           blue_side[0]=='w' && green_side[2]=='w' && orange_side[2]=='w' && orange_side[0]=='w' ){
 left();
 back();
 back();
 left();
 left();
 back_inverted();
 left();
 left();
 back_inverted();
 left();
 left();
 back();
 back();
 left();
}

 else if(white_side[7]=='w' && white_side[3]=='w' && white_side[4]=='w' && white_side[5]=='w' && white_side[1]=='w' && //23
                red_side[0]=='w' && blue_side[2]=='w' && blue_side[0]=='w' && orange_side[2]=='w' ){
 down();
 back();
 back();
 down();
 down();
 back_inverted();
 down();
 down();
 back_inverted();
 down();
 down();
 back();
 back();
 down();
}

 else if(white_side[7]=='w' && white_side[3]=='w' && white_side[4]=='w' && white_side[5]=='w' && white_side[1]=='w' && //24
                      red_side[0]=='w' && red_side[2]=='w' && blue_side[2]=='w' && green_side[0]=='w' ){
 right();
 back();
 back();
 right();
 right();
 back_inverted();
 right();
 right();
 back_inverted();
 right();
 right();
 back();
 back();
 right();
 
}

 else if(white_side[7]=='w' && white_side[3]=='w' && white_side[4]=='w' && white_side[5]=='w' && white_side[1]=='w' && //25
              red_side[0]=='w' && red_side[2]=='w' && orange_side[2]=='w' && orange_side[0]=='w' ){
 left();
 up();
 back();
 up_inverted();
 back_inverted();
 up();
 back();
 up_inverted();
 back_inverted();
 up();
 back();
 up_inverted();
 back_inverted();
 left_inverted(); 
}

else if(white_side[7]=='w' && white_side[3]=='w'  && white_side[5]=='w' && white_side[1]=='w' && //26
              blue_side[0]=='w' && blue_side[2]=='w' && green_side[2]=='w' && green_side[0]=='w' ){
                down();
                left();
                back();
                left_inverted();
                back_inverted();
                left();
                back();
                left_inverted();
                back_inverted();
                left();
                back();
                left_inverted();
                back_inverted();
                down_inverted();
                
                }
else if(white_side[7]=='w' && white_side[3]=='w' ){//27
                right();
                back();
                down();
                back_inverted();
                down_inverted();
                right_inverted();
                }
else if(white_side[1]=='w' && white_side[3]=='w' ){//28
                up();
                back();
                right();
                back_inverted();
                right_inverted();
                up_inverted();
                
                }



else if (white_side[4]=='w' && white_side[5]=='w' && white_side[1]=='w'){//29
  left();
  back();
  up();
  back_inverted();
  up_inverted();
  left_inverted(); //29
}
else if (white_side[7]=='w' && white_side[4]=='w' && white_side[5]=='w'){
  down();
  back();
  left();
  back_inverted();
  left_inverted();
  down_inverted(); //30
}
else if (white_side[7]=='w' && white_side[4]=='w' && white_side[1]=='w'){
  left();
  up();
  back();
  up_inverted();
  back_inverted();
  left_inverted(); //31
}
else if (white_side[3]=='w' && white_side[4]=='w' && white_side[5]=='w'){
  down();
  left();
  back();
  left_inverted();
  back_inverted();
  down_inverted(); //32
}
else if (white_side[4]=='w'){
  left();
  up();
  back();
  up_inverted();
  right_inverted();
  left_inverted();
  right();
  back();
  down();
  back_inverted();
  down_inverted();
  right_inverted(); //33
}
}
 
  }


  void PLL(){
  Serial.println();
  Serial.print("PLL: ");
  Serial.println();
    if(red_side[0]=='r' && red_side[1]=='r'  && red_side[2]=='r' && blue_side[0]=='b'&& blue_side[1]=='b'&& blue_side[2]=='b'&& orange_side[0]=='o'&&
          orange_side[1]=='o'&&  orange_side[2]=='o'&& green_side[0]=='g' && green_side[1]=='g' && green_side[2]=='g' )
  {
     print_whole_cube();
    Serial.print(" Cube was Solved.");
    solve_stage=9;
  
  }
  else if(solve_stage==8){

 //case 1
if(red_side[0]=='r'&&red_side[1]=='r'&&red_side[2]=='o'&&blue_side[0]=='b'&&blue_side[1]=='b'&&blue_side[2]=='o'&&orange_side[0]=='g'&&orange_side[1]=='o'&&orange_side[2]=='b'&&green_side[0]=='r'&&green_side[1]=='g'&&green_side[2]=='g'){

 right();down_inverted();right();up();up();right_inverted();down();right();up();up();right();right();  
}
//case 2
else if(red_side[0]=='o'&&red_side[1]=='r'&&red_side[2]=='r'&&blue_side[0]=='b'&&blue_side[1]=='b'&&blue_side[2]=='o'&&orange_side[0]=='g'&&orange_side[1]=='o'&&orange_side[2]=='g'&&green_side[0]=='r'&&green_side[1]=='g'&&green_side[2]=='b'){

 down();left_inverted();down();right();right();down_inverted();left();down();right();right();down();down();  
}
//case 3
else if(red_side[0]=='r'&&red_side[1]=='r'&&red_side[2]=='o'&&blue_side[0]=='g'&&blue_side[1]=='b'&&blue_side[2]=='b'&&orange_side[0]=='o'&&orange_side[1]=='o'&&orange_side[2]=='g'&&green_side[0]=='r'&&green_side[1]=='g'&&green_side[2]=='b'){

 left();up_inverted();left();down();down();left_inverted();up();left();down();down();left();left();  
}
//case 4
else if(red_side[0]=='b'&&red_side[1]=='r'&&red_side[2]=='b'&&blue_side[0]=='o'&&blue_side[1]=='b'&&blue_side[2]=='g'&&orange_side[0]=='r'&&orange_side[1]=='o'&&orange_side[2]=='o'&&green_side[0]=='g'&&green_side[1]=='g'&&green_side[2]=='r'){

 up();right_inverted();up();left();left();up_inverted();right();up();left();left();up();up();  
}
//case 5
else if(red_side[0]=='g'&&red_side[1]=='r'&&red_side[2]=='r'&&blue_side[0]=='b'&&blue_side[1]=='b'&&blue_side[2]=='g'&&orange_side[0]=='r'&&orange_side[1]=='o'&&orange_side[2]=='b'&&green_side[0]=='o'&&green_side[1]=='g'&&green_side[2]=='o'){

  right_inverted();up();right_inverted();down();down();right();up_inverted();right_inverted();down();down();right();right();
}
//case 6
else if(red_side[0]=='g'&&red_side[1]=='r'&&red_side[2]=='g'&&blue_side[0]=='r'&&blue_side[1]=='b'&&blue_side[2]=='b'&&orange_side[0]=='o'&&orange_side[1]=='o'&&orange_side[2]=='r'&&green_side[0]=='b'&&green_side[1]=='g'&&green_side[2]=='o'){

  down_inverted();right();down_inverted();left();left();down();right_inverted();down_inverted();left();left();down();down();
}
//case 7
else if(red_side[0]=='o'&&red_side[1]=='r'&&red_side[2]=='g'&&blue_side[0]=='r'&&blue_side[1]=='b'&&blue_side[2]=='r'&&orange_side[0]=='b'&&orange_side[1]=='o'&&orange_side[2]=='o'&&green_side[0]=='g'&&green_side[1]=='g'&&green_side[2]=='b'){

  left_inverted();down();left_inverted();up();up();left();down_inverted();left_inverted();up();up();left();left();
}
//case 8
else if(red_side[0]=='r'&&red_side[1]=='r'&&red_side[2]=='o'&&blue_side[0]=='g'&&blue_side[1]=='b'&&blue_side[2]=='r'&&orange_side[0]=='b'&&orange_side[1]=='o'&&orange_side[2]=='b'&&green_side[0]=='o'&&green_side[1]=='g'&&green_side[2]=='g'){

  up_inverted();left();up_inverted();right();right();up();left_inverted();up_inverted();right();right();up();up();
}
//case 9
else if(red_side[0]=='r'&&red_side[1]=='o'&&red_side[2]=='r'&&blue_side[0]=='b'&&blue_side[1]=='b'&&blue_side[2]=='b'&&orange_side[0]=='o'&&orange_side[1]=='g'&&orange_side[2]=='o'&&green_side[0]=='g'&&green_side[1]=='r'&&green_side[2]=='g'){

  left();back_inverted();left();back();left();back();left();back_inverted();left_inverted();back_inverted();left_inverted();left_inverted();
}
//case 10
else if(red_side[0]=='r'&&red_side[1]=='b'&&red_side[2]=='r'&&blue_side[0]=='b'&&blue_side[1]=='g'&&blue_side[2]=='b'&&orange_side[0]=='o'&&orange_side[1]=='o'&&orange_side[2]=='o'&&green_side[0]=='g'&&green_side[1]=='r'&&green_side[2]=='g'){

  up();back_inverted();up();back();up();back();up();back_inverted();up_inverted();back_inverted();up();up();
}
//case 11
else if(red_side[0]=='r'&&red_side[1]=='b'&&red_side[2]=='r'&&blue_side[0]=='b'&&blue_side[1]=='o'&&blue_side[2]=='b'&&orange_side[0]=='o'&&orange_side[1]=='r'&&orange_side[2]=='o'&&green_side[0]=='g'&&green_side[1]=='g'&&green_side[2]=='g'){

  right();back_inverted();right();back();right();back();right();back_inverted();right_inverted();back_inverted();right();right();
}
//case 12
 else if(red_side[0]=='r'&&red_side[1]=='r'&&red_side[2]=='r'&&blue_side[0]=='b'&&blue_side[1]=='o'&&blue_side[2]=='b'&&orange_side[0]=='o'&&orange_side[1]=='g'&&orange_side[2]=='o'&&green_side[0]=='g'&&green_side[1]=='b'&&green_side[2]=='g'){

  down();back_inverted();down();back();down();back();down();back_inverted();down_inverted();back_inverted();down();down();
}
//case 13
 else if(red_side[0]=='r'&&red_side[1]=='g'&&red_side[2]=='r'&&blue_side[0]=='b'&&blue_side[1]=='b'&&blue_side[2]=='b'&&orange_side[0]=='o'&&orange_side[1]=='r'&&orange_side[2]=='o'&&green_side[0]=='g'&&green_side[1]=='o'&&green_side[2]=='g'){

  left();left();back();left();back();left_inverted();back_inverted();left_inverted();back_inverted();left_inverted();back();left_inverted();
}
//case 14
 else if(red_side[0]=='r'&&red_side[1]=='g'&&red_side[2]=='r'&&blue_side[0]=='b'&&blue_side[1]=='r'&&blue_side[2]=='b'&&orange_side[0]=='o'&&orange_side[1]=='o'&&orange_side[2]=='o'&&green_side[0]=='g'&&green_side[1]=='b'&&green_side[2]=='g'){

  up();up();back();up();back();up_inverted();back_inverted();up_inverted();back_inverted();up_inverted();back();up_inverted();
}
//case 15
 else if(red_side[0]=='r'&&red_side[1]=='o'&&red_side[2]=='r'&&blue_side[0]=='b'&&blue_side[1]=='r'&&blue_side[2]=='b'&&orange_side[0]=='o'&&orange_side[1]=='b'&&orange_side[2]=='o'&&green_side[0]=='g'&&green_side[1]=='g'&&green_side[2]=='g'){

  right();right();back();right();back();right_inverted();back_inverted();right_inverted();back_inverted();right_inverted();back();right_inverted();
}

//case 16
else if(red_side[0]=='r'&&red_side[1]=='r'&&red_side[2]=='r'&&blue_side[0]=='b'&&blue_side[1]=='g'&&blue_side[2]=='b'&&orange_side[0]=='o'&&orange_side[1]=='b'&&orange_side[2]=='o'&&green_side[0]=='g'&&green_side[1]=='o'&&green_side[2]=='g'){

  down();down();back();down();back();down_inverted();back_inverted();down_inverted();back_inverted();down_inverted();back();down_inverted();
}
//case 17
else if(red_side[0]=='r'&&red_side[1]=='o'&&red_side[2]=='r'&&blue_side[0]=='b'&&blue_side[1]=='g'&&blue_side[2]=='b'&&orange_side[0]=='o'&&orange_side[1]=='r'&&orange_side[2]=='o'&&green_side[0]=='g'&&green_side[1]=='b'&&green_side[2]=='g'){

  up();up();down();down();front();up();up();down();down();back();back();up();up();down();down();front();up();up();down();down();
}
//case 18
else if(red_side[0]=='r'&&red_side[1]=='o'&&red_side[2]=='r'&&blue_side[0]=='b'&&blue_side[1]=='b'&&blue_side[2]=='o'&&orange_side[0]=='g'&&orange_side[1]=='r'&&orange_side[2]=='b'&&green_side[0]=='o'&&green_side[1]=='g'&&green_side[2]=='g'){

  right();back();right_inverted();back_inverted();right_inverted();up();right();right();back_inverted();right_inverted();back_inverted();right();back();right_inverted();up_inverted();
}
//case 19
else if(red_side[0]=='g'&&red_side[1]=='r'&&red_side[2]=='r'&&blue_side[0]=='b'&&blue_side[1]=='g'&&blue_side[2]=='b'&&orange_side[0]=='o'&&orange_side[1]=='o'&&orange_side[2]=='g'&&green_side[0]=='r'&&green_side[1]=='b'&&green_side[2]=='o'){

  down();back();down_inverted();back_inverted();down_inverted();right();down();down();back_inverted();down_inverted();back_inverted();down();back();down_inverted();right_inverted();
}
//case 20
else if(red_side[0]=='b'&&red_side[1]=='o'&&red_side[2]=='g'&&blue_side[0]=='r'&&blue_side[1]=='b'&&blue_side[2]=='b'&&orange_side[0]=='o'&&orange_side[1]=='r'&&orange_side[2]=='o'&&green_side[0]=='g'&&green_side[1]=='g'&&green_side[2]=='r'){

  left();back();left_inverted();back_inverted();left_inverted();down();left();left();back_inverted();left_inverted();back_inverted();left();back();left_inverted();down();
}
//case 21
else if(red_side[0]=='r'&&red_side[1]=='r'&&red_side[2]=='b'&&blue_side[0]=='o'&&blue_side[1]=='g'&&blue_side[2]=='r'&&orange_side[0]=='b'&&orange_side[1]=='o'&&orange_side[2]=='o'&&green_side[0]=='g'&&green_side[1]=='b'&&green_side[2]=='g'){

  up();back();up_inverted();back_inverted();up_inverted();left();up();up();back_inverted();up_inverted();back_inverted();up();back();up_inverted();back_inverted();
}
//case 22
else if(red_side[0]=='r'&&red_side[1]=='b'&&red_side[2]=='b'&&blue_side[0]=='o'&&blue_side[1]=='r'&&blue_side[2]=='r'&&orange_side[0]=='b'&&orange_side[1]=='o'&&orange_side[2]=='o'&&green_side[0]=='g'&&green_side[1]=='g'&&green_side[2]=='g'){

  up();back();up_inverted();left_inverted();up();back();up_inverted();back_inverted();up_inverted();left();up();up();back_inverted();up_inverted();back_inverted();
}
//case 23
else if(red_side[0]=='r'&&red_side[1]=='r'&&red_side[2]=='r'&&blue_side[0]=='b'&&blue_side[1]=='o'&&blue_side[2]=='o'&&orange_side[0]=='g'&&orange_side[1]=='b'&&orange_side[2]=='b'&&green_side[0]=='o'&&green_side[1]=='g'&&green_side[2]=='g'){

  right();back();right_inverted();up_inverted();right();back();right_inverted();back_inverted();right_inverted();up();right();right();back_inverted();right_inverted();back_inverted();
}
//case 24
else if(red_side[0]=='g'&&red_side[1]=='r'&&red_side[2]=='r'&&blue_side[0]=='b'&&blue_side[1]=='b'&&blue_side[2]=='b'&&orange_side[0]=='o'&&orange_side[1]=='g'&&orange_side[2]=='g'&&green_side[0]=='r'&&green_side[1]=='o'&&green_side[2]=='o'){

  down();back();down_inverted();right_inverted();down();back();down_inverted();back_inverted();down_inverted();right();down();down();back_inverted();down_inverted();back_inverted();
}
//case 25
else if(red_side[0]=='b'&&red_side[1]=='g'&&red_side[2]=='g'&&blue_side[0]=='r'&&blue_side[1]=='b'&&blue_side[2]=='b'&&orange_side[0]=='o'&&orange_side[1]=='o'&&orange_side[2]=='o'&&green_side[0]=='g'&&green_side[1]=='r'&&green_side[2]=='r'){

  left();back();left_inverted();down_inverted();left();back();left_inverted();back_inverted();left_inverted();down();left();left();back_inverted();left_inverted();back_inverted();
}
//case 26
else if(red_side[0]=='r'&&red_side[1]=='r'&&red_side[2]=='r'&&blue_side[0]=='b'&&blue_side[1]=='b'&&blue_side[2]=='o'&&orange_side[0]=='g'&&orange_side[1]=='g'&&orange_side[2]=='b'&&green_side[0]=='o'&&green_side[1]=='o'&&green_side[2]=='g'){

  up_inverted();back();down_inverted();back();back();up();back_inverted();up_inverted();back();back();up();down();back_inverted();
}
//case 27
else if(red_side[0]=='g'&&red_side[1]=='g'&&red_side[2]=='r'&&blue_side[0]=='b'&&blue_side[1]=='b'&&blue_side[2]=='b'&&orange_side[0]=='o'&&orange_side[1]=='o'&&orange_side[2]=='g'&&green_side[0]=='r'&&green_side[1]=='r'&&green_side[2]=='o'){

  right_inverted();back();left_inverted();back();back();right();back_inverted();right_inverted();back();back();right();left();back_inverted();
}
//case 28
else if(red_side[0]=='b'&&red_side[1]=='b'&&red_side[2]=='g'&&blue_side[0]=='r'&&blue_side[1]=='r'&&blue_side[2]=='b'&&orange_side[0]=='o'&&orange_side[1]=='o'&&orange_side[2]=='o'&&green_side[0]=='g'&&green_side[1]=='g'&&green_side[2]=='r'){

  down_inverted();back();up_inverted();back();back();down();back_inverted();down_inverted();back();back();down();up();back_inverted();
}
//case 29
else if(red_side[0]=='r'&&red_side[1]=='r'&&red_side[2]=='b'&&blue_side[0]=='o'&&blue_side[1]=='o'&&blue_side[2]=='r'&&orange_side[0]=='b'&&orange_side[1]=='b'&&orange_side[2]=='o'&&green_side[0]=='g'&&green_side[1]=='g'&&green_side[2]=='g'){

  left_inverted();back();right_inverted();back();back();left();back_inverted();left_inverted();back();back();down();right();back_inverted();
}

//31
else if(red_side[0]=='r' && red_side[1]=='g' && red_side[2]=='b' && blue_side[0]=='o'  && blue_side[1]=='b' && blue_side[2]=='r' 
&& orange_side[0]=='b' && orange_side[1]=='o' && orange_side[2]=='o' && green_side[0]=='g' && green_side[1]=='r' && green_side[2]=='g'){
  left_inverted();
  back();
  back();
  left();
  back();
  back();
  left_inverted();
  down();
  left();
  back();
  left_inverted();
  back_inverted();
  left_inverted();
  down_inverted();
  left();
  left();
  back();
  
  
}
//32
else if(red_side[0]=='r' && red_side[1]=='b' && red_side[2]=='r' && blue_side[0]=='b'  && blue_side[1]=='r' && blue_side[2]=='o' 
&& orange_side[0]=='g' && orange_side[1]=='o' && orange_side[2]=='b' && green_side[0]=='o' && green_side[1]=='g' && green_side[2]=='g'){
  up_inverted();
  back();
  back();
  up();
  back();
  back();
  up_inverted();
  left();
  up();
  back();
  up_inverted();
  back_inverted();
  up_inverted();
  left_inverted();
  up();
  up();
  back_inverted();
  
  
  
}
//33
else if(red_side[0]=='g' && red_side[1]=='r' && red_side[2]=='r' && blue_side[0]=='b'  && blue_side[1]=='o' && blue_side[2]=='b' 
&& orange_side[0]=='o' && orange_side[1]=='b' && orange_side[2]=='g' && green_side[0]=='r' && green_side[1]=='g' && green_side[2]=='o'){
  right_inverted();
  back();
  back();
  right();
  back();
  back();
  right_inverted();
  up();
  right();
  back();
  right_inverted();
  back_inverted();
  right_inverted();
  up_inverted();
  right();
  right();
  back_inverted();
  
  
}
//34
else if(red_side[0]=='b' && red_side[1]=='r' && red_side[2]=='g' && blue_side[0]=='r'  && blue_side[1]=='b' && blue_side[2]=='b' 
&& orange_side[0]=='o' && orange_side[1]=='g' && orange_side[2]=='o' && green_side[0]=='g' && green_side[1]=='o' && green_side[2]=='r'){
  down_inverted();
  back();
  back();
  down();
  back();
  back();
  down_inverted();
  right();
  down();
  back();
  down_inverted();
  back_inverted();
  down_inverted();
  right_inverted();
  down();
  down();
  back_inverted();
  
  
}
//35
else if(red_side[0]=='r' && red_side[1]=='r' && red_side[2]=='b' && blue_side[0]=='o'  && blue_side[1]=='b' && blue_side[2]=='r' 
&& orange_side[0]=='b' && orange_side[1]=='g' && orange_side[2]=='o' && green_side[0]=='g' && green_side[1]=='o' && green_side[2]=='g'){
  right();
  back();
  back();
  right_inverted();
  back();
  back();
  right();
  down_inverted();
  right_inverted();
  back_inverted();
  right();
  back();
  right();
  down();
  right();
  right();
  back();
  
}
//36
else if(red_side[0]=='r' && red_side[1]=='g' && red_side[2]=='r' && blue_side[0]=='b'  && blue_side[1]=='b' && blue_side[2]=='r' 
&& orange_side[0]=='g' && orange_side[1]=='o' && orange_side[2]=='b' && green_side[0]=='o' && green_side[1]=='r' && green_side[2]=='g'){
  down();
  back();
  back();
  down_inverted();
  back();
  back();
  down();
  left_inverted();
  down_inverted();
  back_inverted();
  down();
  back();
  down();
  left();
  down();
  down();
  back();
  
}
//37
else if(red_side[0]=='g' && red_side[1]=='b' && red_side[2]=='r' && blue_side[0]=='b'  && blue_side[1]=='r' && blue_side[2]=='b' 
&& orange_side[0]=='o' && orange_side[1]=='o' && orange_side[2]=='g' && green_side[0]=='r' && green_side[1]=='g' && green_side[2]=='o'){
  left();
  back();
  back();
  left_inverted();
  back();
  back();
  left();
  up_inverted();
  left_inverted();
  back_inverted();
  left();
  back();
  left();
  up();
  left();
  left();
  back();
  
}
//38
else if(red_side[0]=='b' && red_side[1]=='r' && red_side[2]=='g' && blue_side[0]=='r'  && blue_side[1]=='o' && blue_side[2]=='b' 
&& orange_side[0]=='o' && orange_side[1]=='b' && orange_side[2]=='o' && green_side[0]=='g' && green_side[1]=='g' && green_side[2]=='r'){
  up();
  back();
  back();
  up_inverted();
  back();
  back();
  up();
  right_inverted();
  up_inverted();
  back_inverted();
  up();
  back();
  up();
  right();
  up();
  up();
  back();
}
//39
else if(red_side[0]=='r' && red_side[1]=='r' && red_side[2]=='o' && blue_side[0]=='g'  && blue_side[1]=='o' && blue_side[2]=='b' 
&& orange_side[0]=='o' && orange_side[1]=='b' && orange_side[2]=='r' && green_side[0]=='b' && green_side[1]=='g' && green_side[2]=='g'){
  up_inverted();
  back();
  up_inverted();
  back_inverted();
  right_inverted();
  up_inverted();
  right();
  right();
  back_inverted();
  right_inverted();
  back();
  right_inverted();
  up();
  right();
  up();
  
}
//40
else if(red_side[0]=='o' && red_side[1]=='r' && red_side[2]=='r' && blue_side[0]=='b'  && blue_side[1]=='b' && blue_side[2]=='g' 
&& orange_side[0]=='r' && orange_side[1]=='g' && orange_side[2]=='o' && green_side[0]=='g' && green_side[1]=='o' && green_side[2]=='b'){
  right_inverted();
  back();
  right_inverted();
  back_inverted();
  down_inverted();
  right_inverted();
  down();
  down();
  back_inverted();
  down_inverted();
  back();
  down();
  down();
  right();
  down();
  right();
  
}
//41
else if(red_side[0]=='r' && red_side[1]=='g' && red_side[2]=='o' && blue_side[0]=='g'  && blue_side[1]=='b' && blue_side[2]=='b' 
&& orange_side[0]=='o' && orange_side[1]=='o' && orange_side[2]=='r' && green_side[0]=='b' && green_side[1]=='r' && green_side[2]=='g'){
  down_inverted();
  back();
  down_inverted();
  back_inverted();
  left_inverted();
  down_inverted();
  left();
  left();
  back_inverted();
  left_inverted();
  back();
  left_inverted();
  down();
  left();
  down();
}
//42
else if(red_side[0]=='o' && red_side[1]=='b' && red_side[2]=='r' && blue_side[0]=='b'  && blue_side[1]=='r' && blue_side[2]=='g' 
&& orange_side[0]=='r' && orange_side[1]=='o' && orange_side[2]=='o' && green_side[0]=='g' && green_side[1]=='g' && green_side[2]=='b'){
  left_inverted();
  back();
  left_inverted();
  back_inverted();
  up_inverted();
  left_inverted();
  up();
  up();
  back_inverted();
  up_inverted();
  back();
  up_inverted();
  left();
  up();
  left();
}
//43
else if(red_side[0]=='b' && red_side[1]=='o' && red_side[2]=='b' && blue_side[0]=='o'  && blue_side[1]=='r' && blue_side[2]=='g' 
&& orange_side[0]=='r' && orange_side[1]=='b' && orange_side[2]=='o' && green_side[0]=='g' && green_side[1]=='g' && green_side[2]=='r'){
  right();
  right();
  front();
  up();
  back_inverted();
  up();
  back();
  up_inverted();
  front();
  right();
  right();
  down();
  back_inverted();
  down_inverted();
}
//44
else if(red_side[0]=='r' && red_side[1]=='r' && red_side[2]=='b' && blue_side[0]=='o'  && blue_side[1]=='g' && blue_side[2]=='o' 
&& orange_side[0]=='g' && orange_side[1]=='b' && orange_side[2]=='r' && green_side[0]=='b' && green_side[1]=='o' && green_side[2]=='g'){
  down();
  down();
  front();
  right();
  back_inverted();
  right();
  back();
  right_inverted();
  front();
  down();
  down();
  left();
  back_inverted();
  left_inverted();
  
}
//45
else if(red_side[0]=='o' && red_side[1]=='g' && red_side[2]=='r' && blue_side[0]=='b'  && blue_side[1]=='b' && blue_side[2]=='o' 
&& orange_side[0]=='g' && orange_side[1]=='r' && orange_side[2]=='g' && green_side[0]=='r' && green_side[1]=='o' && green_side[2]=='b'){
  left();
  left();
  front();
  down();
  back_inverted();
  down();
  back();
  down_inverted();
  front();
  left();
  left();
  up();
  back_inverted();
  up_inverted();

}
else if (blue_side[0]=='g' && blue_side[1]=='r' && blue_side[2]=='b' && red_side[2]=='o' && red_side[1]=='g' && red_side[0]=='b' && green_side[2]=='r' && green_side[1]=='b' && green_side[0]=='r' && orange_side[0]=='o' && orange_side[1]=='o' && orange_side[2]=='g'){
up();
up();
front();
left();
back_inverted();
left();
back();
left_inverted();
front();
up();
up();
right();
back_inverted();
right_inverted();//46
}
else if (blue_side[0]=='r' && blue_side[1]=='g' && blue_side[2]=='b' && red_side[2]=='g' && red_side[1]=='b' && red_side[0]=='g' && green_side[2]=='o' && green_side[1]=='r' && green_side[0]=='b' && orange_side[0]=='o' && orange_side[1]=='o' && orange_side[2]=='r'){
right();
back();
right_inverted();
up();
up();
front_inverted();
left();
back_inverted();
left_inverted();
back();
left_inverted();
front();
up();
up();//47
}
else if (blue_side[0]=='r' && blue_side[1]=='o' && blue_side[2]=='r' && red_side[2]=='g' && red_side[1]=='b' && red_side[0]=='o' && green_side[2]=='b' && green_side[1]=='g' && green_side[0]=='g' && orange_side[0]=='b' && orange_side[1]=='r' && orange_side[2]=='o'){
down();
back();
down_inverted();
right();
right();
front_inverted();
up();
back_inverted();
up_inverted();
back();
up();
front();
right();
right();//48
}
else if (blue_side[0]=='g' && blue_side[1]=='o' && blue_side[2]=='r' && red_side[2]=='o' && red_side[1]=='r' && red_side[0]=='r' && green_side[2]=='g' && green_side[1]=='b' && green_side[0]=='o' && orange_side[0]=='b' && orange_side[1]=='g' && orange_side[2]=='b' ){
  left();
   back();
   left_inverted();
   down();
   down();
   front_inverted();
   right();
   back_inverted();
   right_inverted();
   back();
   right();
   front();
   down();
   down();//49
}
else if (blue_side[0]=='b' && blue_side[1]=='b' && blue_side[2]=='g' && red_side[2]=='r' && red_side[1]=='o' && red_side[0]=='g' && green_side[2]=='o' && green_side[1]=='r' && green_side[0]=='o' && orange_side[0]=='r' && orange_side[1]=='r' && orange_side[2]=='b'){
  up();
  back();
  up_inverted();
  left();
  left();
  front_inverted();
  down();
  back_inverted();
  down_inverted();
  back();
  down_inverted();
  front();
  left();
  left();//50
}
else if (blue_side[0]=='r' && blue_side[1]=='b' && blue_side[2]=='b' && red_side[2]=='g' && red_side[1]=='o' && red_side[0]=='g' && green_side[2]=='o' && green_side[1]=='r' && green_side[0]=='b' && orange_side[0]=='o' && orange_side[1]=='g' && orange_side[2]=='r'){
  right();
  right();
  front();
  down_inverted();
  back();
  down_inverted();
  back_inverted();
  down();
  front_inverted();
  right();
  right();
  up_inverted();
  back();
  up();//57
}
else if (blue_side[0]=='r' && blue_side[1]=='g' && blue_side[2]=='r' && red_side[2]=='g' && red_side[1]=='b' && red_side[0]=='o' && green_side[2]=='b' && green_side[1]=='r' && green_side[0]=='g' && orange_side[0]=='b' && orange_side[1]=='o' && orange_side[2]=='o'){
  down();
  down();
  front();
  left_inverted();
  back();
  left_inverted();
  back_inverted();
  left();
  front_inverted();
  down();
  down();
  right_inverted();
  back();
  right();//58
}
else if (blue_side[0]=='g' && blue_side[1]=='o' && blue_side[2]=='r' && red_side[2]=='o' && red_side[1]=='b' && red_side[0]=='r' && green_side[2]=='g' && green_side[1]=='g' && green_side[0]=='o' && orange_side[0]=='b' && orange_side[1]=='r' && orange_side[2]=='b'){
  left();
  left();
  front();
  up_inverted();
  back();
  up_inverted();
  back_inverted();
  up();
  front_inverted();
  left();
  left();
  down_inverted();
  back();
  down();//59
}




//60
else if(red_side[0]=='g' && red_side[1]=='r' && red_side[2]=='r' && blue_side[0]=='b'  && blue_side[1]=='o' && blue_side[2]=='g' 
&& orange_side[0]=='r' && orange_side[1]=='g' && orange_side[2]=='b' && green_side[0]=='o' && green_side[1]=='b' && green_side[2]=='o'){

   up();
   up();
   front();
   right_inverted();
   back();
   right_inverted();
   back_inverted();
   right();
   front_inverted();
   up();
   up();
   left_inverted();
   back();
   left();
  
}
//61
else if(red_side[0]=='b' && red_side[1]=='g' && red_side[2]=='b' && blue_side[0]=='o'  && blue_side[1]=='r' && blue_side[2]=='g' 
&& orange_side[0]=='r' && orange_side[1]=='o' && orange_side[2]=='o' && green_side[0]=='g' && green_side[1]=='b' && green_side[2]=='r'){
right_inverted();
back_inverted();
right();
down();
down();
front();
left_inverted();
back();
left();
back_inverted();
left();
front_inverted();
down();
down();

  
}
//62
else if(red_side[0]=='r' && red_side[1]=='o' && red_side[2]=='b' && blue_side[0]=='o'  && blue_side[1]=='r' && blue_side[2]=='o' 
&& orange_side[0]=='g' && orange_side[1]=='b' && orange_side[2]=='r' && green_side[0]=='b' && green_side[1]=='g' && green_side[2]=='g'){

  down_inverted();
  back_inverted();
  down();
  left();
  left();
  front();
  up_inverted();
  back();
  up();
  back_inverted();
  up();
  front_inverted();
  left();
  left();
}
//case 63
else if(red_side[0]=='o' && red_side[1]=='r' && red_side[2]=='r' && blue_side[0]=='b'  && blue_side[1]=='g' && blue_side[2]=='o' 
&& orange_side[0]=='g' && orange_side[1]=='b' && orange_side[2]=='g' && green_side[0]=='r' && green_side[1]=='o' && green_side[2]=='b'){
left_inverted();
back_inverted();
left();
up();
up();
front();
right_inverted();
back();
right();
back_inverted();
right();
front_inverted();
up();
up();
  
}


//case 64
else if(red_side[0]=='b' && red_side[1]=='g' && red_side[2]=='o' && blue_side[0]=='g'  && blue_side[1]=='b' && blue_side[2]=='b' 
&& orange_side[0]=='o' && orange_side[1]=='r' && orange_side[2]=='g' && green_side[0]=='r' && green_side[1]=='o' && green_side[2]=='r'){
up_inverted();
back_inverted();
up();
right();
right();
front();
down_inverted();
back();
down();
back_inverted();
down();
front_inverted();
right();
right();
  
}

//case 65
else if(red_side[0]=='g' && red_side[1]=='o' && red_side[2]=='r' && blue_side[0]=='b'  && blue_side[1]=='b' && blue_side[2]=='b' 
&& orange_side[0]=='o' && orange_side[1]=='r' && orange_side[2]=='g' && green_side[0]=='r' && green_side[1]=='g' && green_side[2]=='o'){
left_inverted();
back();
back();
left_inverted();
back_inverted();
up_inverted();
left_inverted();
up();
up();
back_inverted();
up_inverted();
back();
up_inverted();
left_inverted();
up();
back_inverted();
left();
  
}


//case 66
else if(red_side[0]=='b' && red_side[1]=='r' && red_side[2]=='g' && blue_side[0]=='r'  && blue_side[1]=='g' && blue_side[2]=='b' 
&& orange_side[0]=='o' && orange_side[1]=='o' && orange_side[2]=='o' && green_side[0]=='g' && green_side[1]=='b' && green_side[2]=='r'){
up_inverted();
back();
back();
up_inverted();
back_inverted();
right_inverted();
up_inverted();
right();
right();
back_inverted();
right_inverted();
back();
right_inverted();
up();
right();
back_inverted();
up();
  
}

//case 67
else if(red_side[0]=='r' && red_side[1]=='o' && red_side[2]=='b' && blue_side[0]=='o'  && blue_side[1]=='b' && blue_side[2]=='r' 
&& orange_side[0]=='b' && orange_side[1]=='r' && orange_side[2]=='o' && green_side[0]=='g' && green_side[1]=='g' && green_side[2]=='g'){
right_inverted();
back();
back();
right_inverted();
back_inverted();
down_inverted();
right_inverted();
down();
down();
back_inverted();
down_inverted();
back();
down_inverted();
right();
down();
back_inverted();
right();

  
}

//case 68
else if(red_side[0]=='r' && red_side[1]=='r' && red_side[2]=='r' && blue_side[0]=='b'  && blue_side[1]=='g' && blue_side[2]=='o' 
&& orange_side[0]=='g' && orange_side[1]=='o' && orange_side[2]=='b' && green_side[0]=='o' && green_side[1]=='b' && green_side[2]=='g'){
down_inverted();
back();
back();
down_inverted();
back_inverted();
left_inverted();
down_inverted();
left();
left();
back_inverted();
left_inverted();
back();
left_inverted();
down_inverted();
left();
back_inverted();
down();
  
}

//case 69
else if(red_side[0]=='r' && red_side[1]=='b' && red_side[2]=='r' && blue_side[0]=='b'  && blue_side[1]=='r' && blue_side[2]=='b' 
&& orange_side[0]=='o' && orange_side[1]=='g' && orange_side[2]=='o' && green_side[0]=='g' && green_side[1]=='o' && green_side[2]=='g'){
up();
up();
down();
down();
front();
up();
up();
down();
down();
back();
up_inverted();
down();
left();
left();
right();
right();
up_inverted();
down();
back();
back();
up();
up();
down();
down();  
}

//case 70
else if(red_side[0]=='r' && red_side[1]=='g' && red_side[2]=='r' && blue_side[0]=='b'  && blue_side[1]=='o' && blue_side[2]=='b' 
&& orange_side[0]=='o' && orange_side[1]=='b' && orange_side[2]=='o' && green_side[0]=='g' && green_side[1]=='r' && green_side[2]=='g'){
right();
right();
left();
left();
front();
right();
right();
left();
left();
back();
right_inverted();
left();
up();
up();
down();
down();
right_inverted();
left();
back();
back();
right();
right();
left();
left();
  
}

//case 71
else if(red_side[0]=='r' && red_side[1]=='b' && red_side[2]=='o' && blue_side[0]=='g'  && blue_side[1]=='r' && blue_side[2]=='b' 
&& orange_side[0]=='o' && orange_side[1]=='o' && orange_side[2]=='r' && green_side[0]=='b' && green_side[1]=='g' && green_side[2]=='g'){
right();
down();
back_inverted();
down();
back_inverted();
down();
back();
down_inverted();
right_inverted();
down();
back();
down_inverted();
back_inverted();
down_inverted();
right();
down();
right_inverted();
  
}

//case 72
else if(red_side[0]=='o' && red_side[1]=='r' && red_side[2]=='r' && blue_side[0]=='b'  && blue_side[1]=='o' && blue_side[2]=='g' 
&& orange_side[0]=='r' && orange_side[1]=='b' && orange_side[2]=='o' && green_side[0]=='g' && green_side[1]=='g' && green_side[2]=='b'){
down();
left();
back_inverted();
left();
back_inverted();
left();
back();
left_inverted();
down_inverted();
left_inverted();
back();
left_inverted();
back_inverted();
left_inverted();
down();
left();
down();
  
}

//case 73
else if(red_side[0]=='r' && red_side[1]=='r' && red_side[2]=='o' && blue_side[0]=='g'  && blue_side[1]=='b' && blue_side[2]=='b' 
&& orange_side[0]=='o' && orange_side[1]=='g' && orange_side[2]=='r' && green_side[0]=='b' && green_side[1]=='o' && green_side[2]=='g'){
left();
up();
back_inverted();
up_inverted();
back_inverted();
up();
back();
up_inverted();
left_inverted();
up();
back();
up_inverted();
back_inverted();
up_inverted();
left();
up();
left_inverted();



  
}

//case 74
else if(red_side[0]=='o' && red_side[1]=='g' && red_side[2]=='r' && blue_side[0]=='b'  && blue_side[1]=='b' && blue_side[2]=='g' 
&& orange_side[0]=='r' && orange_side[1]=='o' && orange_side[2]=='o' && green_side[0]=='g' && green_side[1]=='r' && green_side[2]=='b'){
up();
right();
back_inverted();
right_inverted();
back_inverted();
right();
back();
right_inverted();
up_inverted();
right();
back();
right_inverted();
back_inverted();
right_inverted();
up();
right();
up_inverted();

  
}

//case 75
else if(red_side[0]=='o' && red_side[1]=='o' && red_side[2]=='r' && blue_side[0]=='b'  && blue_side[1]=='b' && blue_side[2]=='g' 
&& orange_side[0]=='r' && orange_side[1]=='r' && orange_side[2]=='o' && green_side[0]=='g' && green_side[1]=='g' && green_side[2]=='b'){
up_inverted();
back();
down_inverted();
back();
back();
up();
back_inverted();
down();
up_inverted();
back();
down_inverted();
back();
back();
up();
back_inverted();
down();
back_inverted();

  
}

//case 76
else if(red_side[0]=='r' && red_side[1]=='r' && red_side[2]=='o' && blue_side[0]=='g'  && blue_side[1]=='g' && blue_side[2]=='b' 
&& orange_side[0]=='o' && orange_side[1]=='o' && orange_side[2]=='r' && green_side[0]=='b' && green_side[1]=='b' && green_side[2]=='g'){
right_inverted();
back();
left_inverted();
back();
back();
right();
back_inverted();
left();
right_inverted();
back();
left_inverted();
back();
back();
right();
back_inverted();
left();
back_inverted();

  
}


//case 77
else if(red_side[0]=='o' && red_side[1]=='r' && red_side[2]=='r' && blue_side[0]=='b'  && blue_side[1]=='g' && blue_side[2]=='g' 
&& orange_side[0]=='r' && orange_side[1]=='o' && orange_side[2]=='o' && green_side[0]=='g' && green_side[1]=='b' && green_side[2]=='b'){
left();
back_inverted();
right();
back();
back();
left_inverted();
back();
right_inverted();
left();
back_inverted();
right();
back();
back();
right_inverted();
back();
right_inverted();
back();


  
}

//case 78
else if(red_side[0]=='r' && red_side[1]=='o' && red_side[2]=='o' && blue_side[0]=='g'  && blue_side[1]=='b' && blue_side[2]=='b' 
&& orange_side[0]=='o' && orange_side[1]=='r' && orange_side[2]=='r' && green_side[0]=='b' && green_side[1]=='g' && green_side[2]=='g'){
down();
back_inverted();
up();
back();
back();
down_inverted();
back();
up_inverted();
down();
back_inverted();
up();
back();
back();
up_inverted();
back();
up_inverted();
back();
  
}

//case 79
else if(red_side[0]=='b' && red_side[1]=='r' && red_side[2]=='g' && blue_side[0]=='r'  && blue_side[1]=='b' && blue_side[2]=='o' 
&& orange_side[0]=='g' && orange_side[1]=='o' && orange_side[2]=='b' && green_side[0]=='o' && green_side[1]=='g' && green_side[2]=='r'){
up();
right_inverted();
up_inverted();
left();
up();
right();
up_inverted();
left_inverted();
up();
right();
up_inverted();
left();
up();
right_inverted();
up_inverted();
left_inverted();


  
}

//case 80
else if(red_side[0]=='b' && red_side[1]=='r' && red_side[2]=='g' && blue_side[0]=='o'  && blue_side[1]=='b' && blue_side[2]=='r' 
&& orange_side[0]=='g' && orange_side[1]=='o' && orange_side[2]=='b' && green_side[0]=='r' && green_side[1]=='g' && green_side[2]=='o'){
right();
down_inverted();
right_inverted();
up();
right();
down();
right_inverted();
up_inverted();
right();
down();
right_inverted();
up_inverted();
right();
down_inverted();
right_inverted();
up_inverted();

}
else back();
    
  }
  
  }


void setup()
{
    FStepper.setSpeed(200);
    BStepper.setSpeed(200);
    UStepper.setSpeed(60);
    DStepper.setSpeed(200);
    RStepper.setSpeed(200);
    LStepper.setSpeed(200);  
    Serial.begin(9600);
}

void cube_decide()
{
  switch (solve_stage)
  {
    case 1:
      // Cross
      cube_decide_cross();
      break;
    case 2:
      // Whole Cross
      cube_decide_whole_cross();
      break;
    case 3:
      cube_decide_F2L_RED_BLUE();
      
      break;
    case 4:
      
      cube_decide_F2L_BLUE_ORANGE();
      break;
    case 5:
      cube_decide_F2L_RED_GREEN();
      break;
    case 6:
      cube_decide_F2L_ORANGE_GREEN();
      break;
    case 7:
      WhiteFace();
      break;  
     case 8:
      PLL();
      break;  


  }
}

void solve_cube()
{
  print_whole_cube();
  Serial.println("Solving Cube: ");
  solve_stage = 1;
  while (solve_stage != 9)
  {
    cube_decide();
  }

}

void loop()
{
  solve_cube();
  Serial.println("Done!");
  print_whole_cube();
  Serial.println(nOFm);
  while (true) {}

}
