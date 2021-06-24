#include <iostream>
#include <cstring>


#define INITIAL_SIZE 32

struct Buffer{
    void *data;
    size_t next;
    size_t size;
};

struct Buffer* newBuffer() {
    struct Buffer *b = new Buffer;

    b->data = malloc(INITIAL_SIZE);
    b->size = INITIAL_SIZE;
    b->next =0;

    return b;
}

void reserveSpace(Buffer* b, size_t bytes){
    if((b->next + bytes) > b->size){
        // double size to enforce 0(lg N) rallocs
        b->data = realloc(b->data, b->size * 2);
        b->size *=2;
    }
}

void serializeInt(int x, Buffer* b){
    // assume int == long
    // x = htonl(x);

    reserveSpace(b, sizeof(int));
    memcpy((char*)b->data + b->next, &x, sizeof(int));
    b->next += sizeof(int);
}



struct intFloatString{
    int i;
    // float f;
    // char* s;
};

void serializeIntFloatString(struct intFloatString* toSerialize, struct Buffer* output){
    serializeInt(toSerialize->i, output);
    
}



int main()
{
    intFloatString* toSerialize = new intFloatString;
    Buffer* buf = newBuffer(); 

    toSerialize->i = 42;

    serializeIntFloatString(toSerialize, buf);
    
    std::cout << "Hello World" << "\n";
}

