from tkinter import Tk
from tkinter.filedialog import askopenfilename
virus_signatures = [
    {"name": "Virus Mydoom", "signature": b"\x5E\x8B\x36\x28\xC7\x50\x68\x61\x69\x6C\x20\x66\x69\x72\x75\x6E\x67\x63\x73\x70"},
    {"name": "Worm Conficker", "signature": b"Services.exe"},
    {"name": "Trojan Tiny", "signature": b"\x55\x8B\xEC\x83\xEC\x0C\x83"}
]

def deschide():
    Tk().withdraw()
    locatie = askopenfilename()
    scanare(locatie)

def scanare(locatie):
    try:
        with open(locatie, "rb") as f:
            continut = f.read()
            virus_detectat = False
            for virus in virus_signatures:
                if virus["signature"] in continut:
                    print(f"L-AM GASIT PE FRAIER: {virus['name']} în {locatie}")
                    virus_detectat = True
            if not virus_detectat:
                print(f"Nu e virus în {locatie} :(")
    except Exception as e:
        print(f"Eroare la deschiderea fișierului: {e}")

deschide()
