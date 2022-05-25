#include "AppWindow.h"


int main() {
    AppWindow app;
    if(!app.init()) return(1);

    while(app.isRun()) {
        app.broadcast();
    }

    return 0;
}
