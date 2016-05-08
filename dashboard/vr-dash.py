from tkinter import Tk, Label, Frame, Button, Text, Entry
from tkinter.constants import *

import _thread
from serial import Serial


class VrDash:
    LOG_TYPE_INTERNAL = 'internal'
    LOG_TYPE_TX = 'tx'
    LOG_TYPE_RX = 'rx'

    board = Serial(timeout=.1)

    def __init__(self, master):
        frame = Frame(master)
        frame.pack()

        Label(frame, text="Port").grid(row=0)
        self.w_port = Entry(frame)
        self.w_port.insert(0, 'COM6')
        self.w_port.grid(row=0, column=1, sticky=W + E)

        Label(frame, text="Baudrate").grid(row=1)
        self.w_baudrate = Entry(frame)
        self.w_baudrate.insert(0, '9600')
        self.w_baudrate.grid(row=1, column=1, sticky=W + E)

        Label(frame, text="Interaction log", width=25).grid(row=2, sticky=N)
        self.w_log = Text(frame, height=10)
        self.w_log.grid(row=2, column=1)

        Label(frame, text="Command").grid(row=3)
        self.w_command = Entry(frame)
        self.w_command.grid(row=3, column=1, sticky=W + E)

        self.w_start = Button(frame, text="Connect", command=self.start)
        self.w_start.grid(row=4, column=1, sticky=E, padx=55)

        self.w_send = Button(frame, text="Send", command=self.send)
        self.w_send.grid(row=4, column=1, sticky=E, padx=15)

        self.w_log.tag_config(self.LOG_TYPE_INTERNAL, foreground='blue')
        self.w_log.tag_config(self.LOG_TYPE_RX, foreground='green')
        self.w_log.tag_config(self.LOG_TYPE_TX, foreground='red')

    def connect(self):
        self.board.baudrate = self.w_baudrate.get()
        self.board.port = self.w_port.get()
        if not self.board.is_open:
            self.board.open()
            self.log("Connected", self.LOG_TYPE_INTERNAL)

    def send(self):
        cmd = self.w_command.get()
        self.board.write(cmd.encode('utf-8'))
        self.log(cmd, self.LOG_TYPE_TX)

    def watch_serial(self):
        while True:
            data = self.board.readline()
            if data:
                self.log(data.decode('utf-8'), self.LOG_TYPE_RX)

    def start(self):
        self.connect()
        _thread.start_new(self.watch_serial, ())

    def log(self, msg, rec_type=LOG_TYPE_INTERNAL):
        if not msg.endswith("\r\n"):
            msg += "\r\n"
        self.w_log.insert(INSERT, msg, rec_type)


root = Tk()
root.resizable(0, 0)
root.wm_title('VrDashboard')

app = VrDash(root)

root.mainloop()
