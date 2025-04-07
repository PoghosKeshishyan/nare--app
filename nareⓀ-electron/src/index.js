import { app, BrowserWindow } from 'electron';
import path from 'path';

if (require('electron-squirrel-startup')) app.quit();

let mainWindow;

const createWindow = () => {
  mainWindow = new BrowserWindow({
    width: 800,
    height: 600,
    icon: path.join(__dirname, 'logo.ico'),
  });

  mainWindow.loadURL(`file://${__dirname}/index.html`);
  mainWindow.setMenuBarVisibility(false);
  mainWindow.maximize();
  mainWindow.on('closed', () => mainWindow = null);
  // mainWindow.webContents.openDevTools();
};

app.on('ready', createWindow);
app.on('window-all-closed', () => {if (process.platform !== 'darwin') {app.quit();}});
app.on('activate', () => {if (mainWindow === null) {createWindow();}});
