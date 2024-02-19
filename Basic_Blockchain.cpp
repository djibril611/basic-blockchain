#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>

using namespace std;

struct Block {
    uint32_t index;
    string data;
    string prevHash;
    string hash;
    time_t timestamp;
}

vector<Block> blockchain;

// Function to "simulate" hashing (in a real application, use a cryptographic hash function)
string calculateHash(const Block& block) {
    stringstream ss;
    ss << block.index << block.timestamp << block.data << block.prevHash;
    return ss.str(); // This is just a placeholder. In reality, you should use a cryptographic hash function like SHA-256.
}

// Function to create the first block, aka the "Genesis Block"
void createGenesisBlock() {
    Block genesisBlock;
    genesisBlock.index = 0;
    genesisBlock.timestamp = time(nullptr);
    genesisBlock.data = "Genesis Block";
    genesisBlock.prevHash = "0";
    genesisBlock.hash = calculateHash(genesisBlock);

    blockchain.push_back(genesisBlock);
}

// Function to generate a new block
Block generateNewBlock(const string& blockData) {
    Block newBlock;
    newBlock.index = blockchain.back().index + 1;
    newBlock.timestamp = time(nullptr);
    newBlock.data = blockData;
    newBlock.prevHash = blockchain.back().hash;
    newBlock.hash = calculateHash(newBlock);

    return newBlock;
}

// Function to add a block to the blockchain after validation (simple validation in this example)
void addBlock(Block& newBlock) {
    // In a real blockchain, you would perform more complex validation here
    newBlock.hash = calculateHash(newBlock); // Recalculate the hash for the block
    blockchain.push_back(newBlock);
}

// Function to print the blockchain to console
void printBlockchain() {
    for(const auto& block : blockchain) {
        cout << "Block Index: " << block.index << endl;
        cout << "Block Data: " << block.data << endl;
        cout << "Block Timestamp: " << block.timestamp << endl;
        cout << "Previous Hash: " << block.prevHash << endl;
        cout << "Hash: " << block.hash << endl;
        cout << "-------------------" << endl;
    }
}

int main() {
    // Create the genesis block
    createGenesisBlock();

    // Add a few blocks to the blockchain
    Block block1 = generateNewBlock("Block 1 Data");
    addBlock(block1);

    Block block2 = generateNewBlock("Block 2 Data");
    addBlock(block2);

    // Print the blockchain to the console
    printBlockchain();

    return 0;
}
//cd "/Users/yourusername/folder/filename/" && g++ -std=c++11 Basic_Blockchain.cpp -o Basic_Blockchain && "/Users/djibrilkonate/Documents/Project 0/"Basic_Blockchain
//its to use c++ 11 
