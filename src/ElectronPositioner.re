type t;

[@bs.module] [@bs.new]
external make: BsElectron.BrowserWindow.t => t = "electron-positioner";

[@bs.deriving {jsConverter: newType}]
type coordinates = {
  x: int,
  y: int,
};

[@bs.send]
external calculate:
  (
    t,
    ~position: [@bs.string] [
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
    ~trayBounds: BsElectron.Tray.trayBounds=?,
    unit
  ) =>
  abs_coordinates =
  "";

type position = [
  | `TrayLeft(BsElectron.Tray.trayBounds)
  | `TrayBottomLeft(BsElectron.Tray.trayBounds)
  | `TrayRight(BsElectron.Tray.trayBounds)
  | `TrayBottomRight(BsElectron.Tray.trayBounds)
  | `TrayCenter(BsElectron.Tray.trayBounds)
  | `TrayBottomCenter(BsElectron.Tray.trayBounds)
  | `TopLeft
  | `TopRight
  | `BottomLeft
  | `BottomRight
  | `TopCenter
  | `BottomCenter
  | `LeftCenter
  | `RightCenter
  | `Center
];

let calculate = (t, position: position) =>
  (
    switch (position) {
    | `TrayLeft(trayBounds) =>
      calculate(t, ~position=`TrayLeft, ~trayBounds, ())
    | `TrayBottomLeft(trayBounds) =>
      calculate(t, ~position=`TrayBottomLeft, ~trayBounds, ())
    | `TrayRight(trayBounds) =>
      calculate(t, ~position=`TrayRight, ~trayBounds, ())
    | `TrayBottomRight(trayBounds) =>
      calculate(t, ~position=`TrayBottomRight, ~trayBounds, ())
    | `TrayCenter(trayBounds) =>
      calculate(t, ~position=`TrayCenter, ~trayBounds, ())
    | `TrayBottomCenter(trayBounds) =>
      calculate(t, ~position=`TrayBottomCenter, ~trayBounds, ())
    | `TopLeft as position
    | `TopRight as position
    | `BottomLeft as position
    | `BottomRight as position
    | `TopCenter as position
    | `BottomCenter as position
    | `LeftCenter as position
    | `RightCenter as position
    | `Center as position => calculate(t, ~position, ())
    }
  )
  ->coordinatesFromJs;
