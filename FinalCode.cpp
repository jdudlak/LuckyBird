//Written by Julia Dudlak and Samir Sanchez Tejada
#include <RGBmatrixPanel.h>
#define CLK  8   
#define OE   9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);
const int buttonPin = 13;
const int buttonPin2 = 11; 
const int startButton = 12;
void setup() {
pinMode(buttonPin, INPUT);
Serial.begin(9600);
int buttonState1 = 0;      
int lastButtonState = 0;
int buttonState2 = 0;      
int lastButtonState2 = 0;
int buttonState3 = 0;
int lastButtonState3 = 0;
int ScoreBoard =0;
int highscore=0;
int count = 0;
 
while(count < 20){
 matrix.begin();
if(count == 0){
matrix.setCursor(1, 0); //Prints out the intro screen to the game 
matrix.setTextSize(0.5);   
matrix.setTextColor(matrix.Color333(0,7,0));
matrix.print('H');
matrix.setTextColor(matrix.Color333(0,7,0));
matrix.print('E');
matrix.setTextColor(matrix.Color333(0,7,0));
matrix.print('L');
matrix.setTextColor(matrix.Color333(0,7,0));
matrix.print('L');
matrix.setTextColor(matrix.Color333(0,7,0));
matrix.print('O');
matrix.setTextColor(matrix.Color333(0,7,0));
matrix.print('!');
delay(1000);
matrix.fillScreen(matrix.Color333(0, 0, 0));
matrix.setCursor(1, 0); 
matrix.setTextSize(1);  
matrix.setTextColor(matrix.Color333(0,7,0));
matrix.print('L');
matrix.setTextColor(matrix.Color333(0,7,0));
matrix.print('U');
matrix.setTextColor(matrix.Color333(0,7,0));
matrix.print('C');
matrix.setTextColor(matrix.Color333(0,7,0));
matrix.print('K');
matrix.setTextColor(matrix.Color333(0,7,0));
matrix.print('Y');
matrix.setTextColor(matrix.Color333(0,7,0));
matrix.setCursor(1, 9);  // next line
matrix.setTextColor(matrix.Color333(0,7,0));
matrix.print('B');
matrix.setTextColor(matrix.Color333(0,7,0));
matrix.print('I');
matrix.setTextColor(matrix.Color333(0,7,0));
matrix.print('R');
matrix.setTextColor(matrix.Color333(0,7,0));
matrix.print('D');
matrix.setTextColor(matrix.Color333(0,7,0));
delay(1000);
matrix.fillScreen(matrix.Color333(0, 0, 0));
delay(500);
}
 
matrix.fillScreen(matrix.Color333(0, 0, 0));
int x=0;
int y=0;
int deincrementer1=0;//THIS IS FOR PIPE1
int pipe1height= 9;//THIS IS FOR PIPE1
int pipe1delay=0;
int deincrementer2=0;
int pipe2height=2;
int pipe2delay=0;
int birdheight=8;
 
while(digitalRead(startButton) != 1){//Waits for user input before the game begins
 matrix.setCursor(4, 5); 
 matrix.setTextSize(0.3);  
 matrix.setTextColor(matrix.Color333(0,0,7));
 matrix.print('H');
 matrix.setTextColor(matrix.Color333(0,0,7));
 matrix.print('O');
 matrix.setTextColor(matrix.Color333(0,0,7));
 matrix.print('L');
 matrix.setTextColor(matrix.Color333(0,0,7));
 matrix.print('D');
 delay(1000);
 matrix.fillScreen(matrix.Color333(0, 0, 0));
 matrix.setCursor(4, 5);  
 matrix.setTextSize(0.3);
 matrix.setTextColor(matrix.Color333(0,0,7));
 matrix.print('B');
 matrix.setTextColor(matrix.Color333(0,0,7));
 matrix.print('L');
 matrix.setTextColor(matrix.Color333(0,0,7));
 matrix.print('U');
 matrix.setTextColor(matrix.Color333(0,0,7));
 matrix.print('E');
 delay(1000);
 matrix.fillScreen(matrix.Color333(0, 0, 0));
 matrix.setCursor(10, 5); 
 matrix.setTextSize(0.3); 
 matrix.setTextColor(matrix.Color333(0,0,7));
 matrix.print('T');
 matrix.setTextColor(matrix.Color333(0,0,7));
 matrix.print('O');
 delay(1000);
 matrix.fillScreen(matrix.Color333(0, 0, 0));
 matrix.setCursor(4, 5);  
 matrix.setTextSize(0.3);  
 matrix.setTextColor(matrix.Color333(0,0,7));
 matrix.print('P');
 matrix.setTextColor(matrix.Color333(0,0,7));
 matrix.print('L');
 matrix.setTextColor(matrix.Color333(0,0,7));
 matrix.print('A');
 matrix.setTextColor(matrix.Color333(0,0,7));
 matrix.print('Y');
 delay(1000);
 matrix.fillScreen(matrix.Color333(0, 0, 0));
}
x=0;
while(x==0){//This starts the game and reads the up and down buttons
buttonState1 = digitalRead(buttonPin);
buttonState2 = digitalRead(buttonPin2);
matrix.drawPixel(3, birdheight, matrix.Color333(7, 7, 0));//Draws the bird to the screen
if (buttonState1 != lastButtonState) {
 if (buttonState1 == HIGH) {
  if(birdheight>=1){//Makes the bird move down on the screen if the left button is pressed and makes sure that the bird can't go below the screen
   birdheight--;
  }
 }
}
if (buttonState2 != lastButtonState2) {
 if (buttonState2 == HIGH) {
  if(birdheight<=14){//Makes the bird move up on the screen if the right button is pressed and makes sure that the bird can't go above the screen
   birdheight++;
  }
}
}
if(pipe1delay==0){
matrix.drawRect(27-deincrementer1, pipe1height, 5, 16-pipe1height, matrix.Color333(0, 7, 0));//Draws the pipe that runs through the bottom of the screen
if(27-deincrementer1==4 && birdheight>=pipe1height){//These different if statements represent the different triggers that end the game
  x++;
}
if(27-deincrementer1==4 && birdheight==15 && pipe1height==16){
  x++;
}
if(27-deincrementer1==3 && birdheight==15 && pipe1height==16){
  x++;
}
if(27-deincrementer1==2 && birdheight==15 && pipe1height==16){
  x++;
}
if(27-deincrementer1==1 && birdheight==15 && pipe1height==16){
  x++;
}
if(27-deincrementer1==0 && birdheight==15 && pipe1height==16){
  x++;
}
if(27-deincrementer1==3 && birdheight>=pipe1height){
  x++;
}
if(27-deincrementer1==2 && birdheight>=pipe1height){
  x++;
}
if(27-deincrementer1==1 && birdheight>=pipe1height){
  x++;
}
if(27-deincrementer1==0 && birdheight>=pipe1height){
  x++;
}
y++;
deincrementer1++;
}
if(deincrementer1>28){
 ScoreBoard++;//If the player passes one of the bottom pipes they gain a point.
if(birdheight==pipe1height){//One of the hitbox detections that ends the game if hit
 x++;
}
y++;
deincrementer1=0;
pipe1height= random(pipe2height+3,18);
pipe1delay = random(3,20);
}
if(pipe2delay==0){
 matrix.drawRect(27-deincrementer2, 0, 5, pipe2height, matrix.Color333(0, 7, 0));//Draws the second pipe into the game.
 if(27-deincrementer2==4 && birdheight<pipe2height){//Different hitbox detections for if the bird hits the pipe.
  x++;
 }
 if(27-deincrementer2==3 && birdheight<pipe2height){
  x++;
 }
 if(27-deincrementer2==2 && birdheight<pipe2height){
  x++;
 }
 if(27-deincrementer2==1 && birdheight<pipe2height){
  x++;
 }
 if(27-deincrementer2==0 && birdheight<pipe2height){
  x++;
 }
 y++;
 deincrementer2++;
}
if(deincrementer2>28){//Checks if pipe2 has reached the end of the screen and if so generated a random height and delay amount for the next pipe to come in
 if(birdheight<pipe2height){//Hitbox detections when the pipe reaches the end of the screen
  x++;
 }
 y++;
 deincrementer2=0;
 pipe2height= random(2,pipe1height-2);
 pipe2delay = random(3,20);
}
 
if(pipe1delay!=0){//Registers the delay and deincrements until pipe1delay reaches 0 meaning that a new pipe can be printed
pipe1delay--;
}
if(pipe2delay!=0){//Registers the delay and deincrements until pipe2delay reaches 0 meaning that a new pipe can be printed
pipe2delay--;
}
if(y<60){//Variables used to speed up the game as you get further and further
delay(100);
}
else if(y<100){
delay(85);
}
else if(y<300){
delay(65);
}
else if(y<800){
delay(55);
}
else if(y<2000){
delay(45);
}
else{
delay(30);
}
matrix.fillScreen(matrix.Color333(0, 0, 0));
}
matrix.setCursor(6, 5);
matrix.setTextSize(1);   
matrix.setTextColor(matrix.Color333(7,0,0));//Prints out that the game has been lost
matrix.print('H');
matrix.setTextColor(matrix.Color333(7,0,0));
matrix.print('I');
matrix.setTextColor(matrix.Color333(7,0,0));
matrix.print('T');
matrix.setTextColor(matrix.Color333(7,0,0));
matrix.print('!');
delay(2000);
matrix.fillScreen(matrix.Color333(0, 0, 0));
matrix.setCursor(1, 0); 
matrix.setTextSize(1);  
matrix.setTextColor(matrix.Color333(7,7,7));//Prints out the game over screen
matrix.print('G');
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('A');
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('M');
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('E');
matrix.setCursor(1, 9);  // next line
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('O');
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('V');
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('E');
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('R');
matrix.setTextColor(matrix.Color333(7,7,7));
delay(1000);
matrix.fillScreen(matrix.Color333(0, 0, 0));
matrix.setCursor(1, 0); 
matrix.setTextSize(1);   
matrix.setTextColor(matrix.Color333(7,0,7));//Prints out the user's score
matrix.print('S');
matrix.setTextColor(matrix.Color333(7,0,7));
matrix.print('C');
matrix.setTextColor(matrix.Color333(7,0,7));
matrix.print('O');
matrix.setTextColor(matrix.Color333(7,0,7));
matrix.print('R');
matrix.setTextColor(matrix.Color333(7,0,7));
matrix.print('E');
matrix.setCursor(1, 9);  // next line
matrix.setTextColor(matrix.Color333(7,0,7));
matrix.print('C');
matrix.setTextColor(matrix.Color333(7,0,7));
matrix.print('O');
matrix.setTextColor(matrix.Color333(7,0,7));
matrix.print('U');
matrix.setTextColor(matrix.Color333(7,0,7));
matrix.print('N');
matrix.setTextColor(matrix.Color333(7,0,7));
matrix.print('T');
// whew!
delay(1000);
matrix.fillScreen(matrix.Color333(0, 0, 0));
matrix.setCursor(1, 0);  // start at top left, with one pixel of spacing
matrix.setTextSize(1);   // size 1 == 8 pixels high
// print each letter with a rainbow color
matrix.setTextColor(matrix.Color333(7,0,7));
String score= (String)ScoreBoard;
char first=' ';//Changes the score count into different characters that can then be printed out using the LED Display's library
char second=' ';
char third=' ';
char fourth=' ';
char fifth=' ';
char sixth=' ';
for(int i =0; i<score.length(); i++){
if(i==0){
  first=score.charAt(i);
}
if(i==1){
  second=score.charAt(i);
}
if(i==2){
  third=score.charAt(i);
}
if(i==3){
  fourth=score.charAt(i);
}
if(i==4){
  fifth=score.charAt(i);
}
if(i==5){
  sixth=score.charAt(i);
}
}
matrix.fillScreen(matrix.Color333(0, 0, 0));
matrix.setCursor(5, 5);  
matrix.setTextSize(1);   
matrix.setTextColor(matrix.Color333(7,0,7));//Prints out the users score
if(first!=' '){
matrix.print(first);
}
matrix.setTextColor(matrix.Color333(7,0,7));
if(second!=' '){
matrix.print(second);
}
matrix.setTextColor(matrix.Color333(7,0,7));
if(third!=' '){
matrix.print(third);
}
matrix.setTextColor(matrix.Color333(7,0,7));
if(fourth!=' '){
matrix.print(fourth);
}
matrix.setTextColor(matrix.Color333(7,0,7));
if(fifth!=' '){
matrix.print(fifth);
}
matrix.setTextColor(matrix.Color333(7,0,7));
if(sixth!=' '){
matrix.print(sixth);
}
delay(2000);
matrix.fillScreen(matrix.Color333(0, 0, 0));
matrix.setCursor(1, 0); 
matrix.setTextSize(1);   
matrix.setTextColor(matrix.Color333(7,7,7));//Prints out the high score
matrix.print('H');
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('I');
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('G');
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('H');
matrix.setCursor(1, 9);  // next line
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('S');
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('C');
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('O');
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('R');
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('E');
delay(1000);

if(ScoreBoard>highscore){//Checks whether the high score needs to be changed
  highscore=ScoreBoard;
}
ScoreBoard=0;
score= (String) highscore;
first=' ';
second=' ';
third=' ';
fourth=' ';
fifth=' ';
sixth=' ';
for(int i =0; i<score.length(); i++){//Assigns the high score numbers
if(i==0){
  first=score.charAt(i);
}
if(i==1){
  second=score.charAt(i);
}
if(i==2){
  third=score.charAt(i);
}
if(i==3){
  fourth=score.charAt(i);
}
if(i==4){
  fifth=score.charAt(i);
}
if(i==5){
  sixth=score.charAt(i);
}
}
matrix.fillScreen(matrix.Color333(0, 0, 0));
matrix.setCursor(5, 5); 
matrix.setTextSize(1);  
matrix.setTextColor(matrix.Color333(7,7,7));
if(first!=' '){//Prints out the high score to the display
matrix.print(first);
}
matrix.setTextColor(matrix.Color333(7,7,7));
if(second!=' '){
matrix.print(second);
}
matrix.setTextColor(matrix.Color333(7,7,7));
if(third!=' '){
matrix.print(third);
}
matrix.setTextColor(matrix.Color333(7,7,7));
if(fourth!=' '){
matrix.print(fourth);
}
matrix.setTextColor(matrix.Color333(7,7,7));
if(fifth!=' '){
matrix.print(fifth);
}
matrix.setTextColor(matrix.Color333(7,7,7));
if(sixth!=' '){
matrix.print(sixth);
}

delay(2000);
matrix.fillScreen(matrix.Color333(0, 0, 0));
matrix.setCursor(1, 0); 
matrix.setTextColor(matrix.Color333(7,7,7));//Asks the play to play again
matrix.print('P');
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('L');
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('A');
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('Y');
matrix.setCursor(1, 9);  // next line
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('A');
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('G');
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('A');
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('I');
matrix.setTextColor(matrix.Color333(7,7,7));
matrix.print('N');
delay(2000);
count++;//Loops back to the intro
}
}
void loop() {
}
