#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ����ͣ�����ṹ
#define MAX_PARKING_SPOTS 5  // ͣ������λ����
#define MAX_CAR_NAME 20      // �������Ƶ���󳤶�

// ���ƺŽṹ
typedef struct {
    char car_name[MAX_CAR_NAME];  // ���ƺŻ���
} Car;

// ����ͣ�������нṹ
typedef struct {
    Car parking_spots[MAX_PARKING_SPOTS];  // �洢��λ������
    int front;  // ����ͷ��
    int rear;   // ����β��
    int size;   // ��ǰͣ�����еĳ�������
} ParkingLot;

// ��ʼ��ͣ����
void initParkingLot(ParkingLot* lot) {
    lot->front = 0;
    lot->rear = 0;
    lot->size = 0;
}

// �ж�ͣ�����Ƿ�����
int isParkingFull(ParkingLot* lot) {
    return lot->size == MAX_PARKING_SPOTS;
}

// �ж�ͣ�����Ƿ�Ϊ��
int isParkingEmpty(ParkingLot* lot) {
    return lot->size == 0;
}

// �볡�����������볡
void carEntry(ParkingLot* lot, char* car_name) {
    if (isParkingFull(lot)) {
        printf("ͣ����������������Ҫ�ȴ���\n");
        return;
    }
    // ������ӵ�����β��
    strcpy_s(lot->parking_spots[lot->rear].car_name, car_name);
    lot->rear = (lot->rear + 1) % MAX_PARKING_SPOTS;  // ѭ��ʹ��ͣ��λ
    lot->size++;
    printf("���� %s �ɹ�����ͣ������\n", car_name);
}

// ������������������
void carExit(ParkingLot* lot) {
    if (isParkingEmpty(lot)) {
        printf("ͣ����Ϊ�գ�û�г���������\n");
        return;
    }
    // �Ƴ�����ͷ���ĳ���
    printf("���� %s �ɹ�������\n", lot->parking_spots[lot->front].car_name);
    lot->front = (lot->front + 1) % MAX_PARKING_SPOTS;  // ѭ������
    lot->size--;
}

// �鿴ͣ�������
void displayParkingLot(ParkingLot* lot) {
    if (isParkingEmpty(lot)) {
        printf("ͣ����Ϊ�գ�\n");
        return;
    }

    printf("ͣ������ǰ״̬��\n");
    int i = lot->front;
    for (int j = 0; j < lot->size; j++) {
        printf("��λ %d: ���� %s\n", j + 1, lot->parking_spots[i].car_name);
        i = (i + 1) % MAX_PARKING_SPOTS;  // ѭ����ʾ��λ
    }
}

int main() {
    ParkingLot lot;
    initParkingLot(&lot);

    int choice;
    char car_name[MAX_CAR_NAME];

    while (1) {
        printf("\n==== ͣ������λ����ϵͳ ====\n");
        printf("1. �����볡\n");
        printf("2. ��������\n");
        printf("3. �鿴ͣ����״̬\n");
        printf("4. �˳�\n");
        printf("��ѡ�������");
        scanf_s("%d", &choice);
        getchar();  // ��׽���з�

        switch (choice) {
        case 1:
            if (isParkingFull(&lot)) {
                printf("ͣ������������ȴ��ճ�λ��\n");
            }
            else {
                printf("�����복�����ƻ��ƺţ�");
                fgets(car_name, sizeof(car_name), stdin);
                car_name[strcspn(car_name, "\n")] = '\0';  // ȥ��ĩβ�Ļ��з�
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
            printf("�˳�ϵͳ��\n");
            exit(0);
        default:
            printf("��Чѡ�������ѡ��\n");
        }
    }

    return 0;
}
