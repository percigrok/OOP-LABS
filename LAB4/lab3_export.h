#ifndef LAB3_EXPORT_H
#define LAB3_EXPORT_H
 
/**
 * @brief Макрос экспорта классов для dll
 *
 * - при сборке dll (LAB3_BUILD_DLL) классы экспортируются;
 * - при использовании dll (LAB3_USE_DLL) классы импортируются;
 * - при сборке статической библиотеки макрос пустой.
 */
#if defined(_WIN32) && defined(LAB3_BUILD_DLL)
#define LAB3_API __declspec(dllexport)
#elif defined(_WIN32) && defined(LAB3_USE_DLL)
#define LAB3_API __declspec(dllimport)
#else
#define LAB3_API
#endif
 
#endif // LAB3_EXPORT_H