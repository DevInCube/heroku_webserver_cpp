#include <cstdio>

#include "config.h" // Config::TgBotApiKey
#include "heroku_webserver_cpp/heroku.h"
#include "tgbot.h"

int main(int argc, char **argv)
{
    heroku_start_webserver_thread();
    //
    const char *botToken = Config::TgBotApiKey;
    (void)tgbot_run(botToken);
}