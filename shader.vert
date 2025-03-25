#version 330 core
layout(location = 0) in vec3 aPos; // Позиция вершины
layout(location = 1) in vec3 aNormal; // Нормаль

out vec3 FragPos; // Позиция фрагмента
out vec3 Normal; // Нормаль

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
    FragPos = vec3(model * vec4(aPos, 1.0));
    Normal = mat3(transpose(inverse(model))) * aNormal; // Учитываем трансформации
    gl_Position = projection * view * model * vec4(aPos, 1.0);
}
