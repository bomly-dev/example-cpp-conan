#include <openssl/ssl.h>
#include <openssl/err.h>
#include <zlib.h>
#include <stdio.h>

// Reachable: SSL_CTX_new uses openssl/1.1.1s (CVE-2022-3602, CVE-2022-3786)
void init_ssl() {
    SSL_library_init();
    const SSL_METHOD *method = TLS_client_method();
    SSL_CTX *ctx = SSL_CTX_new(method);
    if (!ctx) {
        ERR_print_errors_fp(stderr);
    }
    SSL_CTX_free(ctx);
}

// Reachable: zlib inflate uses zlib/1.2.11 (CVE-2022-37434)
void decompress_data(const unsigned char *src, uLong src_len, unsigned char *dest, uLong dest_len) {
    uncompress(dest, &dest_len, src, src_len);
}

int main() {
    init_ssl();
    printf("SSL initialized\n");
    return 0;
}
