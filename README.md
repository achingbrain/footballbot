# footballbot

A module to control the football bot for NodeBots of London's International NodeBots Day celebrations.

You should install the following sketch on the Dagu mini driver board:

```
const byte MOTOR_SPEED = 0xF0;
const byte MOTOR_DIRECTION = 0xF1;

void setup()
{
  Serial.begin(9600);

  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  if(Serial.available() == 3) {
    digitalWrite(13, HIGH);

    byte command = Serial.read();
    byte pin = Serial.read();
    byte value = Serial.read();

    if(command == MOTOR_SPEED) {
      analogWrite(pin, value);
    } else if(command == MOTOR_DIRECTION) {
      digitalWrite(pin, value);
    }
  }
}
```

Then execute a node script that looks something like:

```javascript
var FootballBot = require('footballbot')

var footballBot = new FootballBot('/dev/tty.linvor-DevB')
footballBot.on('ready', function() {
  var left = footballBot.attach(new FootballBot.Motor({
    pins: {
      pwm: 9,
      dir: 7
    }
  }))

  var right = footballBot.attach(new FootballBot.Motor({
    pins: {
      pwm: 10,
      dir: 8
    }
  }))

  this.repl.inject({
    left: left,
    right: right
  })
})

```

The `FootballBot.Motor` class supports a similar API to the Johnny-Five equivalent.
