from tkinter import Tk, Label, Frame, Button, Text, Entry, Menu, Listbox, OptionMenu, StringVar
from tkinter.constants import *
from serial import Serial


class VrDash:
    board = Serial()

    def __init__(self, master):
        frame = Frame(master)
        frame.pack()

        Label(frame, text="Port").grid(row=0)
        self.w_port = Entry(frame)
        self.w_port.insert(0, 'COM6')
        self.w_port.grid(row=0, column=1, sticky=W+E)

        Label(frame, text="Baudrate").grid(row=1)
        self.w_baudrate = Entry(frame)
        self.w_baudrate.insert(0, '9600')
        self.w_baudrate.grid(row=1, column=1, sticky=W+E)

        Label(frame, text="Interaction log", width=25).grid(row=2, sticky=N)
        self.w_log = Text(frame, height=10)
        self.w_log.grid(row=2, column=1)

        Label(frame, text="Command").grid(row=3)
        self.w_command = Entry(frame)
        self.w_command.grid(row=3, column=1, sticky=W+E)

        self.w_send = Button(frame, text="Send", command=self.send)
        self.w_send.grid(row=4, column=1, sticky=E, padx=15)

    def send(self):
        cmd = self.w_command.get()
        self.w_log.insert(END, cmd)
        print(cmd)


root = Tk()
root.resizable(0, 0)
root.wm_title('VrDashboard')

app = VrDash(root)

root.mainloop()
