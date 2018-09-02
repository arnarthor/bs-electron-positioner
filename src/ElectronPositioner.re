type t;

[@bs.module] [@bs.new]
external make: BsElectron.BrowserWindow.t => t = "electron-positioner";

[@bs.deriving {jsConverter: newType}]
type positions = {
  x: int,
  y: int,
};

[@bs.send]
external calculate:
  (
    t,
    [@bs.string] [
      | [@bs.as "trayCenter"] `TrayCenter
      | [@bs.as "trayLeft"] `TrayLeft
      | [@bs.as "trayBottomLeft"] `TrayBottomLeft
      | [@bs.as "trayRight"] `TrayRight
      | [@bs.as "trayBottomRight"] `TrayBottomRight
      | [@bs.as "trayCenter"] `TrayCenter
      | [@bs.as "trayBottomCenter"] `TrayBottomCenter
      | [@bs.as "topLeft"] `TopLeft
      | [@bs.as "topRight"] `TopRight
      | [@bs.as "bottomLeft"] `BottomLeft
      | [@bs.as "bottomRight"] `BottomRight
      | [@bs.as "topCenter"] `TopCenter
      | [@bs.as "bottomCenter"] `BottomCenter
      | [@bs.as "leftCenter"] `LeftCenter
      | [@bs.as "rightCenter"] `RightCenter
      | [@bs.as "center"] `Center
    ],
    BsElectron.Tray.trayBounds
  ) =>
  abs_positions =
  "";

let calculate = (t, centerPosition, trayBounds) =>
  calculate(t, centerPosition, trayBounds)->positionsFromJs;
