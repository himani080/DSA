#include <iostream>
#include <vector>

int bucket_size = 1000; // Bucket capacity in bytes
int output_rate = 100;  // Output rate in bytes per second
int bucket_level = 0;   // Current data in the bucket

// Function to simulate the leaky bucket algorithm for adding packets
void leaky_bucket(int packet_size) {
    if (packet_size <= (bucket_size - bucket_level)) {
        // Add packet to the bucket
        bucket_level += packet_size;
        std::cout << "Packet of size " << packet_size << " bytes added. "
                  << "Bucket level: " << bucket_level << "/" << bucket_size << ".\n";
    } else {
        // Packet is dropped due to overflow
        std::cout << "Packet of size " << packet_size << " bytes dropped. Bucket full.\n";
    }
}

// Function to leak data at the output rate
void leak() {
    if (bucket_level > 0) {
        int leaked = std::min(output_rate, bucket_level);
        bucket_level -= leaked;
        std::cout << "Leaked " << leaked << " bytes. "
                  << "Bucket level: " << bucket_level << "/" << bucket_size << ".\n";
    } else {
        std::cout << "Bucket is empty. No data to leak.\n";
    }
}

int main() {
    // Simulate packet arrival and leak process
    std::vector<int> packets = {200, 300, 700, 400}; // Example packet sizes

    for (int packet : packets) {
        leaky_bucket(packet); // Add packet to the bucket
        leak();               // Leak data at each time interval
    }

    return 0;
}
