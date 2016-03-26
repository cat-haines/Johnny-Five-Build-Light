var five = require("johnny-five");
var Particle = require("particle-io");

var off = ["000000", "#000000", "off"];

// Create the board
var board = new five.Board({
  io: new Particle({
    token: process.env.PARTICLE_TOKEN,
    deviceId: process.env.PARTICLE_DEVICE_ID
  })
});

var params = process.argv;
if (params.length <= 2) {
  console.log("ERROR: Missing required parameter: color:");
  console.log("  Usage: `node .indicator.js ff0000`");
  process.exit(1);
}

var color = params[2];

board.on("ready", function() {
  var rgb = new five.Led.RGB(["D0", "D1", "D2"]);

  try {
    if (off.indexOf(color) >= 0) {
      rgb.off();
    } else {
      rgb.color(color);
      rgb.on();
    }
    setTimeout(function() { process.exit(0); }, 250);
  }  catch(ex) {
    console.log("ERROR: Invalid value for parameter: color");
    process.exit(1);
  }
});
