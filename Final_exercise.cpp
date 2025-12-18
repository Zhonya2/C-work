#include <iostream>
#include <thread>
#include <vector>
#include <atomic>
#include <chrono>
#include <mutex>

using namespace std;

struct Order
{
    int id;
    int quantity;
    double price;
};

const int TOTAL_ORDERS = 10;

vector<Order> orders;
atomic<int> next_order(0);

double total_revenue = 0.0;
mutex revenue_mtx;

void producer()
{
    for (int i = 0; i < TOTAL_ORDERS; ++i)
    {
        orders.push_back({i + 1, (i + 1) * 2, (i + 1) * 10.0});
        this_thread::sleep_for(chrono::milliseconds(50));
    }
}

void consumer()
{
    while (true)
    {
        int index = next_order.fetch_add(1);

        if (index >= TOTAL_ORDERS)
            return;

        Order o = orders[index];

        this_thread::sleep_for(chrono::milliseconds(100));

        double revenue = o.quantity * o.price;

        {
            lock_guard<mutex> lock(revenue_mtx);
            total_revenue += revenue;
        }
    }
}

int main()
{
    orders.reserve(TOTAL_ORDERS);

    thread producer_thread(producer);
    producer_thread.join();

    thread worker1(consumer);
    thread worker2(consumer);

    worker1.join();
    worker2.join();

    cout << "===== FINAL REPORT =====\n";
    cout << "Orders processed: " << TOTAL_ORDERS << "\n";
    cout << "Total revenue: " << total_revenue << "\n";

    return 0;
}
