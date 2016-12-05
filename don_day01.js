function rotateRight() {
  if (dh != 0) {
    dv = -dh;
    dh = 0;
  } else if (dv != 0) {
    dh = dv;
    dv = 0;
  }
}

function rotateLeft() {
  if (dh != 0) {
    dv = dh;
    dh = 0;
  } else if (dv != 0) {
    dh = -dv;
    dv = 0;
  }
}

var directions = 'R1, L4, L5, L5, R2, R2, L1, L1, R2, L3, R4, R3, R2, L4, L2, R5, L1, R5, L5, L2, L3, L1, R1, R4, R5, L3, R2, L4, L5, R1, R2, L3, R3, L3, L1, L2, R5, R4, R5, L5, R1, L190, L3, L3, R3, R4, R47, L3, R5, R79, R5, R3, R1, L4, L3, L2, R194, L2, R1, L2, L2, R4, L5, L5, R1, R1, L1, L3, L2, R5, L3, L3, R4, R1, R5, L4, R3, R1, L1, L2, R4, R1, L2, R4, R4, L5, R3, L5, L3, R1, R1, L3, L1, L1, L3, L4, L1, L2, R1, L5, L3, R2, L5, L3, R5, R3, L4, L2, R2, R4, R4, L4, R5, L1, L3, R3, R4, R4, L5, R4, R2, L3, R4, R2, R1, R2, L4, L2, R2, L5, L5, L3, R5, L5, L1, R4, L1, R1, L1, R4, L5, L3, R4, R1, L3, R4, R1, L3, L1, R1, R2, L4, L2, R1, L5, L4, L5'.split(', ');

var locations = {};

var dh = 0;
var h = 0;
var dv = 1;
var v = 0;
var firstLocation = '';

for (var i = 0; i < directions.length; i++) {

  var rotate = directions[i].charAt(0);
  var dist = directions[i].substring(1);

  if (rotate == 'R') {
    rotateRight();
  }
  if (rotate == 'L') {
    rotateLeft();
  }

  for (var ii = 0; ii < dist; ii++) {
    if (dh != 0) {
      h += dh;
    }
    if (dv != 0) {
      v += dv;
    }

    if (firstLocation == '') {
      if (!locations[h + ', ' + v]) {
        locations[h + ', ' + v] = 1;
      } else {
        firstLocation = h + ', ' + v;
        console.log('first repeated location ' + h + ', ' + v);
      }
    }
  }
}

console.log('final ' + h + ', ' + v);
