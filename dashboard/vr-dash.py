from kivy.app import App
from kivy.lang import Builder
import serial


class VrDash(App):

    board = serial.Serial('COM6', 9600)

    def send_data(self, data):
        self.board.writelines(bytearray(data, 'utf-8'))

    def build(self):
        root = Builder.load_file('dash-home.kv')
        return root

VrDash().run()
