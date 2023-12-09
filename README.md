# NomobotSK

========== PCB DESIGN FOR NOMOBOT SK ==========

NomobotSK is a educational robot for kids to learn programming and robotics.

## TOP VIEW

![Alt text](https://github.com/edantoni96/NomobotSK/blob/main/docs/NomobotSK_TOP.jpg)

## BOTTOM VIEW

![Alt text](https://github.com/edantoni96/NomobotSK/blob/main/docs/NomobotSK_BOTTOM.jpg)

## SCHEMATIC

[embed](https://github.com/edantoni96/NomobotSK/blob/main/docs/schematic.pdf)

## TESTER

To test the device you can use the under tester/TEST.ino

\***\*KONFIGURASI PIN\*\***

D1; Trig / Servo R
D2; Tombol 2
D3; Tombol 3
D4; DIR2 (-)
D5; DIR2 (+)
D6; DIR1 (-)
D7; DIR1 (+)
D8; LED / Garis L
D0; BUZZ / Garis R

Catatan: Simbol / berarti setiap fungsi perlu diuji atau digunakan secara terpisah.

\***\*Perintah PENGUJIAN\*\***

1. TEST_LED
2. TEST_BUZ
3. TEST_BUTTON
4. TEST_M1
5. TEST_M2
6. TEST_ULRA
7. TEST_LINE

\***\*Instruksi Uji\*\***

1. Buka Test.ino dengan Arduino.
2. compile Test.ino.
3. Hubungkan NodeMCU Anda ke komputer menggunakan kabel USB.
4. Pilih board dan port yang sesuai di Arduino IDE.
5. Unggah kode yang telah dikompilasi ke NodeMCU dengan mengklik tombol "Unggah".
6. Setelah pengunggahan selesai, buka Serial Monitor di Arduino IDE.
7. TEST_LED
   - Nyalakan pin LED
   - Ketik "TEST_LED" di Serial Monitor dan tekan Enter.
   - Pastikan bahwa LED yang terhubung ke pin D8 (Garis L) menyala.
8. TEST_BUZ
   - Nyalakan pin Buzz
   - Ketik "TEST_BUZ" di Serial Monitor dan tekan Enter.
   - Konfirmasikan bahwa buzzer yang terhubung ke pin D0 (Garis R) menghasilkan suara.
9. TEST_BUTTON
   - Nyalakan BTA dan BTB
   - Ketik "TEST_BUTTON" di Serial Monitor dan tekan Enter.
   - Tekan Tombol 2 (terhubung ke pin D2) dan Tombol 3 (terhubung ke pin D3) satu per satu.
   - Amati di Serial Monitor bahwa tekanan tombol yang sesuai terdeteksi.
10. TEST_M1
    - Nyalakan pin M1+ dan M1-
    - Ketik "TEST_M1" di Serial Monitor dan tekan Enter.
    - Pastikan bahwa motor (M1) merespons sesuai dengan sinyal DIR1 (-) dan DIR1 (+) pada pin D6 dan D7.
11. TEST_M2
    - Nyalakan pin M2+ dan M2-
    - Ketik "TEST_M2" di Serial Monitor dan tekan Enter.
    - Pastikan bahwa motor (M2) merespons sesuai dengan sinyal DIR2 (-) dan DIR2 (+) pada pin D4 dan D5.
12. TEST_ULRA
    - Nyalakan pin Echo dan Trig
    - Ketik "TEST_ULRA" di Serial Monitor dan tekan Enter.
    - Jika sensor ultrasonik terhubung, periksa Serial Monitor untuk pembacaan jarak.
13. TEST_LINE
    - Nyalakan pin Garis
    - Ketik "TEST_LINE" di Serial Monitor dan tekan Enter.
    - Amati perilaku sensor garis yang terhubung ke pin D8 (Garis L) dan D0 (Garis R).
    - Pastikan pembacaan sensor tercermin di Serial Monitor.
