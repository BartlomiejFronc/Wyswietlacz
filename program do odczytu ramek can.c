//Uruchomienie Can sockect

int s;

if ((s = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0) {
   perror("Socket");
   return 1;
}

//
//
//

struct ifreq ifr;

strcpy(ifr.ifr_name, "vcan0" );
ioctl(s, SIOCGIFINDEX, &ifr);

//
//
//

struct sockaddr_can addr;

memset(&addr, 0, sizeof(addr));
addr.can_family = AF_CAN;
addr.can_ifindex = ifr.ifr_ifindex;

if (bind(s, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
   perror("Bind");
   return 1;
}

//
//Struktura ramki can
//

struct can_frame {
    canid_t can_id;  /* 32 bit CAN_ID + EFF/RTR/ERR flags */
    __u8    can_dlc; /* frame payload length in byte (0 .. 8) */
    __u8    __pad;   /* padding */
    __u8    __res0;  /* reserved / padding */
    __u8    __res1;  /* reserved / padding */
    __u8    data[8] __attribute__((aligned(8)));
};

//
//Przykładowa ramka can
//

/*

struct can_frame frame;

frame.can_id = 0x555;
frame.can_dlc = 5;
sprintf(frame.data, "Hello");

if (write(s, &frame, sizeof(struct can_frame)) != sizeof(struct can_frame)) {
   perror("Write");
   return 1;
}
*/

//
//Czytanie ramki can
//

int nbytes;
struct can_frame frame;

nbytes = read(s, &frame, sizeof(struct can_frame));

if (nbytes < 0) {
   perror("Read");
   return 1;
}

printf("0x%03X [%d] ",frame.can_id, frame.can_dlc);

for (i = 0; i < frame.can_dlc; i++)
   printf("%02X ",frame.data[i]);

printf("\r\n");

//
//Ustawienia filtrowania ramek can
//

struct can_filter rfilter[1];

rfilter[0].can_id   = 0x550;
rfilter[0].can_mask = 0xFF0;
//rfilter[1].can_id   = 0x200;
//rfilter[1].can_mask = 0x700;

setsockopt(s, SOL_CAN_RAW, CAN_RAW_FILTER, &rfilter, sizeof(rfilter));

//
//Zamknięcie Can socket
//

if (close(s) < 0) {
   perror("Close");
   return 1;
}





