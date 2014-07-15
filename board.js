var util = require('util'),
  EventEmitter = require('events').EventEmitter,
  Repl = require("./repl.js"),
  SerialPort = require("serialport").SerialPort

var FootballBot = function(port) {
  EventEmitter.call(this)

  this._serialPort = new SerialPort(port, {
    baudrate: 9600
  })
  this._serialPort.on('open', function() {

    this.repl = new Repl({
      'board': this
    })

    this.emit('ready')
  }.bind(this))
}
util.inherits(FootballBot, EventEmitter)

FootballBot.prototype.attach = function(motor) {
  motor._serialPort = this._serialPort

  return motor
}

module.exports = FootballBot
