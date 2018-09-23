#include <LedControl.h>
#include <LiquidCrystal.h>

LedControl matrix = LedControl(7,5,6,1);
int const buttonA = 4;
int const buttonB = 3; 
LiquidCrystal lcd(8,9,10,11,12,13);

bool playing;
bool rollFinish;
int numPlayers;
int firstRoll;
int secondRoll;
int thirdRoll;
int outcome;
int dealersOutcome;
int playersOutcome;
int rollsCounter;
int playerRollCount = 0;
bool playersTurn = false;
bool pisser;
bool compare;
bool rolling = false;
int dieSix[] = {B01100110,B01100110,B00000000,B01100110,B01100110,B00000000,B01100110,B01100110};
int dieFive[] = {B01100110,B01100110,B00000000,B00011000,B00011000,B00000000,B01100110,B01100110};
int dieFour[] = {B01100110,B01100110,B00000000,B00000000,B00000000,B00000000,B01100110,B01100110};
int dieThree[] = {B01100000,B01100000,B00000000,B00011000,B00011000,B00000000,B00000110,B00000110};
int dieTwo[] = {B01100000,B01100000,B00000000,B00000000,B00000000,B00000000,B00000110,B00000110};
int dieOne[] = {B00000000,B00000000,B00000000,B00011000,B00011000,B00000000,B00000000,B00000000};

void characterSelect(){
  if(digitalRead(buttonA) == LOW){
    numPlayers++;
    if(numPlayers == 9){
      numPlayers = 2;
    }
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("# of Players:");
    lcd.setCursor(0,1);
    lcd.print(numPlayers);
    delay(200);
  }
  if(digitalRead(buttonB) == LOW){
    playing = true;
    delay(200);
  }
}

void rollingDie(){ 
if(rollFinish == false){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Rolling...");
  matrix.clearDisplay(0);
  delay(2000);
  
  
  firstRoll = random(1,7);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("You got a");
  lcd.setCursor(0,1);
  lcd.print(firstRoll);
  matrix.clearDisplay(0);
  switch(firstRoll){
    case 1:
    for(int i = 0;i<8;i++){
    matrix.setRow(0,i,dieOne[i]);
    }
    break;
    case 2:
    for(int k = 0;k<8;k++){
    matrix.setRow(0,k,dieTwo[k]);
    }
    break;
    case 3:
    for(int h = 0;h<8;h++){
    matrix.setRow(0,h,dieThree[h]);
    }
    break;
    case 4:
    for(int m = 0;m<8;m++){
    matrix.setRow(0,m,dieFour[m]);
    }
    break;
    case 5:
    for(int j = 0;j<8;j++){
    matrix.setRow(0,j,dieFive[j]);
    }
    break;
    case 6:
    for(int l = 0;l<8;l++){
    matrix.setRow(0,l,dieSix[l]);
    }
    break;
  }
  delay(2000);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Rolling...");
  matrix.clearDisplay(0);
  delay(2000);
  
  secondRoll = random(1,7);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("You got a");
  lcd.setCursor(0,1);
  lcd.print(secondRoll);
  matrix.clearDisplay(0);
  switch(secondRoll){
    case 1:
    for(int i = 0;i<8;i++){
    matrix.setRow(0,i,dieOne[i]);
    }
    break;
    case 2:
    for(int k = 0;k<8;k++){
    matrix.setRow(0,k,dieTwo[k]);
    }
    break;
    case 3:
    for(int h = 0;h<8;h++){
    matrix.setRow(0,h,dieThree[h]);
    }
    break;
    case 4:
    for(int m = 0;m<8;m++){
    matrix.setRow(0,m,dieFour[m]);
    }
    break;
    case 5:
    for(int j = 0;j<8;j++){
    matrix.setRow(0,j,dieFive[j]);
    }
    break;
    case 6:
    for(int l = 0;l<8;l++){
    matrix.setRow(0,l,dieSix[l]);
    }
    break;
  }
  delay(2000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Rolling...");
  matrix.clearDisplay(0);
  delay(2000);

  thirdRoll = random(1,7);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("You got a");
  lcd.setCursor(0,1);
  lcd.print(thirdRoll);
  matrix.clearDisplay(0);
  switch(thirdRoll){
    case 1:
    for(int i = 0;i<8;i++){
    matrix.setRow(0,i,dieOne[i]);
    }
    break;
    case 2:
    for(int k = 0;k<8;k++){
    matrix.setRow(0,k,dieTwo[k]);
    }
    break;
    case 3:
    for(int h = 0;h<8;h++){
    matrix.setRow(0,h,dieThree[h]);
    }
    break;
    case 4:
    for(int m = 0;m<8;m++){
    matrix.setRow(0,m,dieFour[m]);
    }
    break;
    case 5:
    for(int j = 0;j<8;j++){
    matrix.setRow(0,j,dieFive[j]);
    }
    break;
    case 6:
    for(int l = 0;l<8;l++){
    matrix.setRow(0,l,dieSix[l]);
    }
    break;
  }
  delay(2000);
  
  rollFinish = true;
  pisser = true;
  }
  if(rollFinish == true){
    if(firstRoll == secondRoll and thirdRoll != secondRoll and thirdRoll != firstRoll){
      outcome = firstRoll;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("You have rolled:");
      lcd.setCursor(0,1);
      lcd.print(firstRoll);
      if(playersTurn == true){
        playerRollCount++;
      }
      pisser = false;
      playersTurn = true;
      rolling = false;
      compare = true;
      matrix.clearDisplay(0);
      delay(1000);
    }
    if(secondRoll == thirdRoll and firstRoll != secondRoll and firstRoll != thirdRoll){
      outcome = secondRoll;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("You have rolled:");
      lcd.setCursor(0,1);
      lcd.print(secondRoll);
      if(playersTurn == true){
        playerRollCount++;
      }
      pisser = false;
      playersTurn = true;
      rolling = false;
      compare = true;
      matrix.clearDisplay(0);
      delay(1000);
    }
    if(firstRoll == thirdRoll and secondRoll != firstRoll and secondRoll != thirdRoll){
      outcome = thirdRoll;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("You have rolled:");
      lcd.setCursor(0,1);
      lcd.print(thirdRoll);
      if(playersTurn == true){
        playerRollCount++;
      }
      pisser = false;
      playersTurn = true;
      rolling = false;
      compare = true;
      matrix.clearDisplay(0);
      delay(1000);
    }
    if(firstRoll == secondRoll and secondRoll == thirdRoll and thirdRoll == firstRoll and firstRoll != 1){ //auto win and wins x3
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("You have rolled");
      lcd.setCursor(0,1);
      lcd.print("a triple!");
      if(playersTurn == false){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Dealer wins 3x!");
        pisser = false;
        rolling = false;
        matrix.clearDisplay(0);
        playing = false;
        delay(1000);
      }
      if(playersTurn == true){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Player wins 3x!");
        pisser = false;
        playersTurn = true;
        rolling = false;
        compare = false;
        playerRollCount++;
        matrix.clearDisplay(0);
        delay(1000);
      }
    }
    if(firstRoll == 1 and secondRoll == 1 and thirdRoll == 1){ //auto loses and loses x3
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("You have rolled");
      lcd.setCursor(0,1);
      lcd.print("snake eyes!!");
      pisser = false;
      if(playersTurn == false){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Dealer loses 3x!");
        pisser = false;
        rolling = false;
        matrix.clearDisplay(0);
        playing = false;
        delay(1000);
      }
      if(playersTurn == true){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Player loses 3x!");
        pisser = false;
        playersTurn = true;
        rolling = false;
        compare = false;
        playerRollCount++;
        matrix.clearDisplay(0);
        delay(1000);
      }
    }
    if(((firstRoll + secondRoll + thirdRoll) == 15) and (firstRoll == 4 or secondRoll == 4 or thirdRoll == 4)){ //auto win
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("You have rolled");
      lcd.setCursor(0,1);
      lcd.print("4,5,6!");
      if(playersTurn == false){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Dealer wins!");
        pisser = false;
        rolling = false;
        matrix.clearDisplay(0);
        playing = false;
        delay(1000);
      }
      if(playersTurn == true){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Player wins!");
        pisser = false;
        playersTurn = true;
        rolling = false;
        compare = false;
        playerRollCount++;
        matrix.clearDisplay(0);
        delay(1000);
      }
    }
    if(((firstRoll + secondRoll + thirdRoll) == 6) and (firstRoll == 3 or secondRoll == 3 or thirdRoll == 3)){ //auto lose
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("You have rolled");
      lcd.setCursor(0,1);
      lcd.print("1,2,3!");
      if(playersTurn == false){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Dealer loses!");
        pisser = false;
        rolling = false;
        matrix.clearDisplay(0);
        playing = false;
        delay(1000);
      }
      if(playersTurn == true){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Player loses");
        pisser = false;
        playersTurn = true;
        rolling = false;
        compare = false;
        playerRollCount++;
        matrix.clearDisplay(0);
        delay(1000);
      }
    }
    else if(pisser == true){
      lcd.clear();
      matrix.clearDisplay(0);
      lcd.setCursor(0,0);
      lcd.print("Aw! You rolled");
      lcd.setCursor(0,1);
      lcd.print("a pisser!");
      rollsCounter++;
      compare = false;
      delay(1000);    
    }
    if(rollsCounter == 3){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("You forfeit");
      lcd.setCursor(0,1);
      lcd.print("this match!");
      rolling = false;
      if(playersTurn == false){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Dealer loses!");
        rolling = false;
        matrix.clearDisplay(0);
        playing = false;
        delay(1000);
      }
      if(playersTurn == true){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Player loses!");
        playersTurn = true;
        rolling = false;
        matrix.clearDisplay(0);
        playerRollCount++;
        compare = false;
        delay(1000);
      }
      matrix.clearDisplay(0);
      delay(1000);
    }
  }
}

void dealerRolls(){
  if(rolling == false){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Dealer's turn");
    lcd.setCursor(0,1);
    lcd.print("Press button A.");
    delay(200);
  }
  if(rolling == true){
    rollFinish = false;
    rollingDie();
    dealersOutcome = outcome;
  }
  if(digitalRead(buttonA) == LOW){
    rolling = true;
    rollsCounter = 0;
    delay(200);
  }
}

void playerRolls(){
  if(rolling == false){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Player's turn");
    lcd.setCursor(0,1);
    lcd.print("Press button A.");
    delay(200);
  }
  if(rolling == true){
    rollFinish = false;
    rollingDie();
    playersOutcome = outcome;
    if(compare == true){
      compareToDealer();
    }
  }
  if(digitalRead(buttonA) == LOW){
    rolling = true;
    rollsCounter = 0;
    delay(200);
  }
}

void gameOver(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("The match is");
  lcd.setCursor(0,1);
  lcd.print("over.");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Press buttonA to");
  lcd.setCursor(0,1);
  lcd.print("pick # players.");
  playing = false;
  playerRollCount = 0;
  playersTurn = false;
  delay(1000);
}

void compareToDealer(){
  if(playersOutcome == dealersOutcome){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Dealer & player");
    lcd.setCursor(0,1);
    lcd.print("rolled equally.");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Player takes");
    lcd.setCursor(0,1);
    lcd.print("nothing.");
    delay(1000);
  }
  if(playersOutcome > dealersOutcome){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Player beat the");
    lcd.setCursor(0,1);
    lcd.print("Dealer!");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Player takes");
    lcd.setCursor(0,1);
    lcd.print("the bet.");
    delay(1000);
  }
  if(playersOutcome < dealersOutcome){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Dealer beat the");
    lcd.setCursor(0,1);
    lcd.print("player!");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Dealer takes");
    lcd.setCursor(0,1);
    lcd.print("the bet.");
    delay(1000);
  }
}


void setup(){
pinMode(buttonA,INPUT_PULLUP);
pinMode(buttonB,INPUT_PULLUP);
matrix.shutdown(0,false);
matrix.setIntensity(0,5);
matrix.clearDisplay(0);
lcd.begin(16,2);
playing = false;
numPlayers = 2;
lcd.setCursor(0,0);
lcd.print("# of Players:");
lcd.setCursor(0,1);
lcd.print(numPlayers);
}

void loop() {
if(playing == false){
  characterSelect();
}
if(playing == true and playersTurn == false){
  dealerRolls();
}
if(playing == true and playersTurn == true and playerRollCount == numPlayers - 1){
  gameOver();
}
if(playing == true and playersTurn == true){
  playerRolls();
}
}
