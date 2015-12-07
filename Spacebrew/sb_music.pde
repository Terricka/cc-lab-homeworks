import ddf.minim.*;
import ddf.minim.analysis.*;
AudioPlayer player;
Minim minim;//audio context
AudioMetaData meta;
BeatDetect beat;
int  r = 300;
float rad = 140;


/*
 * Base Example 
 *
 *   Sketch that features the basic building blocks of a Spacebrew client app.
 * 
 */

import spacebrew.*;
import cc.arduino.*;
import processing.serial.*;



String server="sandbox.spacebrew.cc";
String name="P5 Base Example";
String description ="This is an blank example client that publishes .... and also listens to ...";

Spacebrew sb;
Arduino arduinoTerri;

int ledPin = 13;

color color_on = color(255,0,0);
color color_off = color(random(150+30), random(20+30), random(80+30), 8);
int currentColor = color_off;

void setup() {
  size(900, 600);

   
   minim = new Minim(this);
   player = minim.loadFile("tour.mp3", 2048);
   player.play();
   meta = player.getMetaData();
   beat = new BeatDetect();
    //player.play();
  
  arduinoTerri = new Arduino(this, Arduino.list()[2]);
  arduinoTerri.pinMode(ledPin, Arduino.OUTPUT);

  // instantiate the sb variable
  sb = new Spacebrew( this );

  // add each thing you publish to
  sb.addPublish( "buttonTerricka", "boolean", true );
 sb.addPublish( "button_pressed", "boolean", true ); 

  // add each thing you subscribe to
  sb.addSubscribe( "background color", "boolean" );
  sb.addSubscribe( "background color", "boolean" );
  sb.addSubscribe( "changeit", "boolean");

  // connect to spacebrew
  sb.connect(server, name, description ); // variables from uptop

}



void draw() {
  // do whatever you want to do here 
  size(300, 600); 
  background(random(150+30), random(20+30), random(80+30), 8);
  float t = map(mouseX, 0, width, 0, 1);
  beat.detect(player.mix);
  fill(random(1,255), random(1,255), random(1,255), 3);
  noStroke();
  rect(0, 0, width, height);
  translate(width/2, height/2);
  noFill();
  fill(-1, random(255));
  if (beat.isOnset()) rad = rad*2;
  else rad = 70;
  ellipse(0, 0, 2*rad, 2*rad);
  stroke(-100, 150);
  int bsize = player.bufferSize();
  for (int i = 0; i < bsize - 1; i+=5)
  {
    float x = (r)*cos(i*2*PI/bsize);
    float y = (r)*sin(i*2*PI/bsize);
    float x2 = (r + player.left.get(i)*500)*cos(i*2*PI/bsize);
    float y2 = (r + player.left.get(i)*500)*sin(i*2*PI/bsize);
    line(x, y, x2, y2);
  }
  beginShape();
  noFill();
  stroke(-1, 500);
  for (int i = 0; i < bsize; i+=30)
  {
    float x2 = (r + player.left.get(i)*500)*cos(i*2*PI/bsize);
    float y2 = (r + player.left.get(i)*500)*sin(i*2*PI/bsize);
    vertex(x2, y2);
    pushStyle();
    stroke(-1);
    strokeWeight(2);
    point(x2, y2);
    popStyle();
  }
  endShape();
 // if (flag)
 // showMeta();
 
  if (mousePressed == true){
    background(color_on);
    text("TRUE", width/2, height/2);
  } else {
    
    text("FALSE", width/2, height/2);
    
  }
}

void mousePressed() {
  sb.send("buttonpressed", true);
  background(color_off);
}

void mouseReleased() {
  sb.send("buttonTerricka", false);
}


void onBooleanMessage( String name, boolean value ){
  println("got boolean message " + name + " : " + value);  
  if(value == true){
    arduinoTerri.digitalWrite(ledPin, Arduino.LOW);
  } else {
     arduinoTerri.digitalWrite(ledPin, Arduino.HIGH);
  }
}

