# DeskInfo

DeskInfo is a desk element that can give you information in a unique way. I made it so you can take a look about important data in a moment. It also looks cool on my desk :). It will be sitting in my desk allowing me to check quickly important (or not so important) information quickly.

Demo: https://youtu.be/bCdLNaYsPjg

<img width="4000" height="3000" alt="PXL_20260920_122527494 MACRO_FOCUS MP" src="https://github.com/user-attachments/assets/64179fe1-1529-4680-b147-49f04a6d4287" />

<img width="508" height="426" alt="image" src="https://github.com/user-attachments/assets/4fe5d023-a778-4349-adeb-0f02a538c399" />



Note: The .STEP file does not have the 3D case because the 3D files are closed source on MakerWorld. The link for printing it is on the "thank you" section. The project is functional without that case but the stand is designed for the use with it.


# 🖥️ Features:

- Time
- Current, tomorrow’s and in two days climate. (Including interior temperature and humidity with the DHT11).
- Joke Screen
- Quote Screen
- Last 7 days coding info with Hackatime’s API. (Most worked on project, most used language and total time.)

# 🤖 AI Usage

AI reviewed and checked the code, solved issues and proposed upgrades. Also wrote some code, but not much.


# 🔧 Components:

- CYD ESP32 (ESP32-2432S028)
- USB-C to USB-C elbow*
- Button
- DHT-11
- Wiring

*Not necessary

**Before 3D printing, make sure you components fit the 3D files, some of them might have different sizes. If they do not, feel free to modify whatever you need.**

# 💸 BOM:

| Component            | Quantity | Price per Unit | Total Price | Link                                                              |
|----------------------|----------|----------------|-------------|-------------------------------------------------------------------|
| ESP32-2432S028       | 1        | ≈23.8€ / 26.8$        | ≈23.8€ / 26.8$      | https://es.aliexpress.com/item/1005012152927761.html *            |
| USB-C to USB-C elbow | 1        | ≈2.71€ / 3.05$          | ≈2.71€ / 3.05$      | https://es.aliexpress.com/item/1005012446355987.html *            |
| Button               | 1        | ≈1.16€ / 1.30$          | ≈1.16€ / 1.30$      | https://es.aliexpress.com/item/1005008653041072.html *            |
| DHT-11               | 1        | ≈1.16€ / 1.30$          | ≈1.16€ / 1.30$      | https://es.aliexpress.com/item/1005007636012583.html *            |
| 3D printing filament | ≈50g     | ≈15€ / 16.88$           | ≈0.75€ / 0.84$     | https://www.amazon.es/eSUN-Filament-1-8mm-Black-Printer/          |
|                      |          |                | ≈29.6€ / 33.3$     | *The electronic components links are not exactly the ones I used. |

Maybe it is not the optimal way to do this project. When I bought the CYD, it costed 50% less. Electronics price have increased a lot.
Some of the components, aren't the same I used. Obviously, I used a DHT11 and a button, but maybe not the exact same model. The prices are for when you buy only one component, if you buy them by bulk or in packs it would be significantly cheaper.

# ⚡  Pinout:

| Component Pin | Board Pin |
|---------------|-----------|
| DHT11 VCC     | CN1 3.3V  |
| DHT11 Data    | CN1 IO27  |
| DHT11 GND     | CN1 GND   |
| BUTTON PIN1   | CN1 IO22  |
| BUTTON PIN2   | P3 GND    |

<img width="468" height="371" alt="imatge" src="https://github.com/user-attachments/assets/4c704ce5-9492-42eb-9728-d111767dc4b4" />
<img width="335" height="361" alt="imatge" src="https://github.com/user-attachments/assets/e2cfbabe-7376-4205-872b-65e466b61775" />



# 🌟 Thank You:

Special thank you to the next projects.

CYD Case 3D file: https://makerworld.com/models/3165068

M3 Screws 3D file: https://makerworld.com/en/models/1926503

CYD Mock-Board 3D file: https://www.printables.com/model/1627410-cyd-mock-board/files

DHT11 3D file: https://www.tinkercad.com/things/f1tysLlpl9F

Button 3D file: https://www.thingiverse.com/thing:2988249

Schematics: https://github.com/witnessmenow/ESP32-Cheap-Yellow-Display/tree/main/OriginalDocumentation/5-Schematic

Lopaka: https://lopaka.app

# 🧰 Mounting Guide:

1. Wire everything and insert the CYD into its case with the 3D printed screws.

2. Insert the DHT11 on the back cover.
<img width="1000" height="750" alt="PXL_20260920_120307890 MP" src="https://github.com/user-attachments/assets/91d40c27-34c8-4ab0-95bc-c62448e6a2ca" />

3. Insert the button on its place and secure it with the white stick. (I did it with hot glue).
<img width="300" height="400" alt="PXL_20260920_111249212 MP" src="https://github.com/user-attachments/assets/1e38c234-31e8-4e45-99e3-8038967de1d2" />

4. Put all cables inside. (Not very clean but it works.)
<img width="1000" height="750" alt="PXL_20260920_111901888 MACRO_FOCUS MP" src="https://github.com/user-attachments/assets/e88d071b-6adf-40a7-98df-79ce33908bc9" />
