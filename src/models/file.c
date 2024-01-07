void GLWidget::normalize_model() {
    float meanX = 0;
    float meanY = 0;
    float meanZ = 0;
    float maxVal = -100000000;

    for(unsigned int i = 0; i < data.vertexCount; i = i + 3){

        meanX+=data.vertices[i];
        meanY+=data.vertices[i+1];
        meanZ+=data.vertices[i+2];
    }
    meanX = meanX/data.vertexCount;
    meanY = meanY/data.vertexCount;
    meanZ = meanZ/data.vertexCount;

    move_operation(meanX,meanY,meanZ,&data,&data);

    for(unsigned int i = 0; i < data.vertexCount; i = i+3){
        if (data.vertices[i] > maxVal)
            maxVal = data.vertices[i];
        if (data.vertices[i+1] > maxVal)
            maxVal = data.vertices[i+1];
        if (data.vertices[i+2] > maxVal)
            maxVal = data.vertices[i+2];
    }

    zoom_operation(scale/maxVal, scale/maxVal, scale/maxVal, &data, &data);

}