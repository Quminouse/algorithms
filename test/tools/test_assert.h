#pragma once

bool test_assert(bool expression, const char *message);
bool test_assert(bool expression, const char *fail_message,
                 const char *pass_message);
