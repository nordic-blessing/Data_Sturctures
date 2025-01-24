#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义停车场结构
#define MAX_PARKING_SPOTS 5  // 停车场车位数量
#define MAX_CAR_NAME 20      // 汽车名称的最大长度

// 车牌号结构
typedef struct {
    char car_name[MAX_CAR_NAME];  // 车牌号或车名
} Car;

// 定义停车场队列结构
typedef struct {
    Car parking_spots[MAX_PARKING_SPOTS];  // 存储车位的数组
    int front;  // 队列头部
    int rear;   // 队列尾部
    int size;   // 当前停车场中的车辆数量
} ParkingLot;

// 初始化停车场
void initParkingLot(ParkingLot* lot) {
    lot->front = 0;
    lot->rear = 0;
    lot->size = 0;
}

// 判断停车场是否已满
int isParkingFull(ParkingLot* lot) {
    return lot->size == MAX_PARKING_SPOTS;
}

// 判断停车场是否为空
int isParkingEmpty(ParkingLot* lot) {
    return lot->size == 0;
}

// 入场函数：车辆入场
void carEntry(ParkingLot* lot, char* car_name) {
    if (isParkingFull(lot)) {
        printf("停车场已满，车主需要等待！\n");
        return;
    }
    // 将车添加到队列尾部
    strcpy_s(lot->parking_spots[lot->rear].car_name, car_name);
    lot->rear = (lot->rear + 1) % MAX_PARKING_SPOTS;  // 循环使用停车位
    lot->size++;
    printf("车辆 %s 成功进入停车场！\n", car_name);
}

// 出场函数：车辆出场
void carExit(ParkingLot* lot) {
    if (isParkingEmpty(lot)) {
        printf("停车场为空，没有车辆出场！\n");
        return;
    }
    // 移除队列头部的车辆
    printf("车辆 %s 成功出场！\n", lot->parking_spots[lot->front].car_name);
    lot->front = (lot->front + 1) % MAX_PARKING_SPOTS;  // 循环出车
    lot->size--;
}

// 查看停车场情况
void displayParkingLot(ParkingLot* lot) {
    if (isParkingEmpty(lot)) {
        printf("停车场为空！\n");
        return;
    }

    printf("停车场当前状态：\n");
    int i = lot->front;
    for (int j = 0; j < lot->size; j++) {
        printf("车位 %d: 车辆 %s\n", j + 1, lot->parking_spots[i].car_name);
        i = (i + 1) % MAX_PARKING_SPOTS;  // 循环显示车位
    }
}

int main() {
    ParkingLot lot;
    initParkingLot(&lot);

    int choice;
    char car_name[MAX_CAR_NAME];

    while (1) {
        printf("\n==== 停车场车位管理系统 ====\n");
        printf("1. 车辆入场\n");
        printf("2. 车辆出场\n");
        printf("3. 查看停车场状态\n");
        printf("4. 退出\n");
        printf("请选择操作：");
        scanf_s("%d", &choice);
        getchar();  // 捕捉换行符

        switch (choice) {
        case 1:
            if (isParkingFull(&lot)) {
                printf("停车场已满，请等待空车位！\n");
            }
            else {
                printf("请输入车辆名称或车牌号：");
                fgets(car_name, sizeof(car_name), stdin);
                car_name[strcspn(car_name, "\n")] = '\0';  // 去掉末尾的换行符
                carEntry(&lot, car_name);
            }
            break;
        case 2:
            carExit(&lot);
            break;
        case 3:
            displayParkingLot(&lot);
            break;
        case 4:
            printf("退出系统。\n");
            exit(0);
        default:
            printf("无效选项，请重新选择。\n");
        }
    }

    return 0;
}
