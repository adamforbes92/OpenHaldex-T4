/*

A notes section - only here to describe the functions of each CAN frame.

fwd
  motor1.buf[0] = 0x00;   // various individual bits ('space gas', driving pedal, kick down, clutch, timeout brake, brake intervention, drinks-torque intervention?) was 0x01
  **motor1.buf[1] = 0x00;  // inner engine moment (%): 0.39*(0xF0 / 250) = 97.5% (93.6% <> 0xf0)
  **motor1.buf[2] = 0x00;  // motor speed (rpm): 32 > (low byte) -
  **motor1.buf[3] = 0x00;  // motor speed (rpm): 78 > (high byte) : 0.25 * (32 78) = 819.5 RPM (was 0x4e)  Turns pre-charge pump on / off (0x00 = off, >0x00 = on)
  **motor1.buf[4] = 0x00;  // inner moment (%): 0.39*(0xF0) = 93.6%  (make FE?)
  **motor1.buf[5] = 0x00;  // driving pedal (%): 0.39*(0xF0) = 93.6%  (make FE?)
  **motor1.buf[6] = 0x00;  // torque loss (%): 0.39*(0x20) = 12.48%? (make FE?) slippage?
  **motor1.buf[7] = 0x00;  // drivers moment (%): 0.39*(0xF0) = 93.6%  (make FE?)

5050
  motor1.buf[0] = 0x00;  
  **motor1.buf[1] = 0xFE;  
  **motor1.buf[2] = 0x20;  
  **motor1.buf[3] = 0x4E;  Runs pre-charge pump if >0.  0x2E makes 170, rest zero.  0x3E makes 178
  **motor1.buf[4] = 0xFE; 
  **motor1.buf[5] = 0xFE;  
  **motor1.buf[6] = 0xFF;  slippage.  0x20 makes 198, 0xFE makes 131, 0xFF makes 198
  **motor1.buf[7] = 0xFE;  

fwd
  motor3.buf[0] = 0x00;  // various individual bits ('motor has been launched, only in diesel')
  motor3.buf[1] = 0x50;  // outdoor temperature
  **motor3.buf[2] = 0x00;  // pedal
  **motor3.buf[3] = 0x00;  // wheel command torque (low byte).  If SY_ASG
  **motor3.buf[4] = 0x00;  // wheel command torque (high byte).  If SY_ASG
  motor3.buf[5] = 0x00;  // wheel command torque (0 = positive, 1 = negative).  If SY_ASG
  motor3.buf[6] = 0x00;  // req. torque.  If SY_ASG
  **motor3.buf[7] = 0x00;  // throttle angle (100%)

5050
  motor3.buf[0] = 0x00;  
  motor3.buf[1] = 0x50;  
  **motor3.buf[2] = 0xFE;  // pedal
  **motor3.buf[3] = 0x3E;  // wheel command torque (low byte).  If SY_ASG
  **motor3.buf[4] = 0xA0;  // wheel command torque (high byte).  If SY_ASG
  motor3.buf[5] = 0x00;  
  motor3.buf[6] = 0x00;  
  **motor3.buf[7] = 0xFE;  // throttle angle (100%)

fwd
  bitWrite(bremse1, 7, 1); // force ABS in diag to disable clutch - bit 7
  **brakes1.buf[0] = 0x80;  // asr req was 0x80
  brakes1.buf[1] = bremse1;  // was 0x41 - clutch engage / disengage
  brakes1.buf[2] = 0x00;
  **brakes1.buf[3] = 0x00;  // was 0xF4
  **brakes1.buf[4] = 0x01;  // was 0xFE
  **brakes1.buf[5] = 0x02;  // was 0xFE
  brakes1.buf[6] = 0x00;
  brakes1.buf[7] = bremes1Counter;  // was 0x1E

5050
  brakes1.buf[0] = 0x80;  // asr req
  **brakes1.buf[1] = 0x00; // also controlling slippage.  Brake force
  brakes1.buf[2] = 0x00;
  **brakes1.buf[3] = 0xA; 
  **brakes1.buf[4] = 0xFE;
  **brakes1.buf[5] = 0xFE;
  brakes1.buf[6] = 0x00;
  brakes1.buf[7] = bremes1Counter;

fwd
  brakes3.buf[0] = 0x00;  // low byte, LEFT Front
  brakes3.buf[1] = 0x00;  // high byte, LEFT Front
  brakes3.buf[2] = 0x00;  // low byte, RIGHT Front
  brakes3.buf[3] = 0x00;  // high byte, RIGHT Front
  brakes3.buf[4] = 0x00;  // low byte, LEFT Rear
  brakes3.buf[5] = 0x00;  // high byte, LEFT Rear // 254+10? (5050 returns 0xA)
  brakes3.buf[6] = 0x00;  // low byte, RIGHT Rear
  brakes3.buf[7] = 0x00;  // low byte, RIGHT Rear  // 254+10?

5050
  brakes3.buf[0] = 0xFF;  // low byte, LEFT Front
  brakes3.buf[1] = 0xA;   // high byte, LEFT Front
  brakes3.buf[2] = 0xFF;  // low byte, RIGHT Front
  brakes3.buf[3] = 0xA;   // high byte, RIGHT Front
  brakes3.buf[4] = 0x0;   // low byte, LEFT Rear
  brakes3.buf[5] = 0xA;   // high byte, LEFT Rear // 254+10? (5050 returns 0xA)
  brakes3.buf[6] = 0x0;   // low byte, RIGHT Rear
  brakes3.buf[7] = 0xA;   // low byte, RIGHT Rear  // 254+10?
  HaldexCAN.write(brakes3);

*/