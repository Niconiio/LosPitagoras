include("/home/niio/Descargas/LosPitagoras/QT/build/Desktop_Qt_6_11_1-Debug/.qt/QtDeploySupport.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/TrigonometryViewer-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE "/home/niio/Descargas/LosPitagoras/QT/build/Desktop_Qt_6_11_1-Debug/TrigonometryViewer"
    GENERATE_QT_CONF
)
