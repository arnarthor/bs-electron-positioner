// Generated by BUCKLESCRIPT VERSION 4.0.5, PLEASE EDIT WITH CARE
'use strict';


function coordinatesToJs(param) {
  return {
          x: param[/* x */0],
          y: param[/* y */1]
        };
}

function coordinatesFromJs(param) {
  return /* record */[
          /* x */param.x,
          /* y */param.y
        ];
}

function calculate(t, position) {
  var tmp;
  if (typeof position === "number") {
    tmp = t.calculate((function () {
              switch (position) {
                case 371331211 : 
                    return "trayCenter";
                case -272647875 : 
                    return "trayLeft";
                case -427234744 : 
                    return "trayBottomLeft";
                case -821073434 : 
                    return "trayRight";
                case -934206853 : 
                    return "trayBottomRight";
                case 371331211 : 
                    return "trayCenter";
                case 912382550 : 
                    return "trayBottomCenter";
                case 907161884 : 
                    return "topLeft";
                case 283497767 : 
                    return "topRight";
                case 591950002 : 
                    return "bottomLeft";
                case 858208465 : 
                    return "bottomRight";
                case -269910486 : 
                    return "topCenter";
                case -958443712 : 
                    return "bottomCenter";
                case 731702620 : 
                    return "leftCenter";
                case -745370959 : 
                    return "rightCenter";
                case 980392437 : 
                    return "center";
                
              }
            })(), undefined);
  } else {
    var variant = position[0];
    tmp = variant >= -427234744 ? (
        variant >= 371331211 ? (
            variant >= 912382550 ? t.calculate("trayBottomCenter", position[1]) : t.calculate("trayCenter", position[1])
          ) : (
            variant >= -272647875 ? t.calculate("trayLeft", position[1]) : t.calculate("trayBottomLeft", position[1])
          )
      ) : (
        variant >= -821073434 ? t.calculate("trayRight", position[1]) : t.calculate("trayBottomRight", position[1])
      );
  }
  return coordinatesFromJs(tmp);
}

exports.coordinatesToJs = coordinatesToJs;
exports.coordinatesFromJs = coordinatesFromJs;
exports.calculate = calculate;
/* No side effect */
