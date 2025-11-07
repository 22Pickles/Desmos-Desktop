// shared.h

#ifndef SHARED_H
#define SHARED_H

#define APP_VERSION "v1.12"

typedef enum {
    APP_GRAPHING,
    APP_GEOMETRY,
    APP_GRAPHING_3D,
    APP_NOTEBOOK,
    APP_COUNT
} AppType;

typedef struct {
    const char* name;
    const char* favicon_path;
    const char* base_url_path;
} AppConfig;

extern const AppConfig ALL_APP_CONFIGS[];


#endif // SHARED_H