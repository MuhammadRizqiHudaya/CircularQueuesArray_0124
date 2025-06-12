#include <iostream>
using namespace std;

class Queue 
{
private:
    static const int max = 5;
    int FRONT, REAR;
    int queue_array[5];

public:
    Queue() 
    {
        FRONT = -1;
        REAR = -1;
    }

    void insert()
    {
        int num;
        cout << "enter a number:";
        cin >> num;
        cout << endl;

        //1.cek apakah antrian penuh
        if ((FRONT == 0 && REAR == max -1)|| (FRONT == REAR + 1)) 
        {
            cout << "\nqueue overflow\n" << endl;
            return;
        }

        //2.cek apakah antrian kosong
        if (FRONT == -1) 
        {
            FRONT = 0;
            REAR = 0;
        } 
        else 
        {
        if (REAR == max -1)
        REAR=0;
        else
        REAR = REAR + 1;
        } 
        queue_array[REAR]=num;
    }

    void remove ()
    {
        //cek apakah antrian kosong
        if (FRONT == -1) 
        {
            cout << "\nqueue underflow\n" << endl;
            return;
        }
        cout << "\n the element deleted from the queue is:" << queue_array[FRONT] << "\n";
        if (FRONT == REAR)
        {
            FRONT = -1;
            REAR = -1;
        }
        else
        {
            //jika elemen yang dihapus berada di posisi terakhir array kembali ke awal array
            if (FRONT == max -1)
            FRONT = 0;
            else
            FRONT = FRONT + 1;
        }
    }

    void display()
    {
        int FRONT_position = FRONT;
        int REAR_position = REAR;

        //cek apakah antrian kosong
        if (FRONT == -1)
        {
            cout << "queue is empty\n";
            return;
        }

        cout << "\nelements in the queue are:\n";
        //jika FRONT_position <= rear position, iterasi dari FRONT hingga REAR
        if (FRONT_position <= REAR_position)
        {
            while (FRONT_position <= REAR_position)
            {
                cout << queue_array[FRONT_position] << "";
                FRONT_position++;
            }
            cout << endl;
        }
        else
        {
            //jika FRONT_position > rear position, iterasi dari FRONT hingga akhir array
            while (FRONT_position <= max -1)
            {
                cout << queue_array[FRONT_position] << "";
                FRONT_position++;
            }

            FRONT_position = 0;

             while (FRONT_position <= REAR_position)
            {
                cout << queue_array[FRONT_position] << "";
                FRONT_position++;
            }
            cout << endl;
        }
    }

};


        
    }
}