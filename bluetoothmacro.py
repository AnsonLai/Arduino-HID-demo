import bluetooth

# print("Performing inquiry...")

# nearby_devices = bluetooth.discover_devices(duration=8, lookup_names=True,
#                                             flush_cache=True, lookup_class=False)

# print("Found {} devices".format(len(nearby_devices)))

# for addr, name in nearby_devices:
#   try:
#     print("   {} - {}".format(addr, name))
#   except UnicodeEncodeError:
#     print("   {} - {}".format(addr, name.encode("utf-8", "replace")))


import socket
import random
import time

serverMACAddress = '98:D3:31:40:34:1A'
port = 1
s = socket.socket(socket.AF_BLUETOOTH, socket.SOCK_STREAM, socket.BTPROTO_RFCOMM)
s.connect((serverMACAddress,port))
while 1:
  # x1234y1234z
  time.sleep(2)
  mouse_coords = "x" + str(random.randint(0, 1000)).zfill(4) + "y" + str(random.randint(0, 1000)).zfill(4) + "z"
  print(mouse_coords)
  s.send(bytes(mouse_coords, 'UTF-8'))
  # §
s.close()
