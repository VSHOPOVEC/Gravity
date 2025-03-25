out vec4 FragColor;

in vec3 FragPos;
in vec3 Normal;

uniform vec3 lightPos; // Позиция источника света
uniform vec3 lightColor; // Цвет света
uniform vec3 objectColor; // Цвет объекта

void main() {
    // Простое затенение по Фонгу
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    vec3 result = (diffuse) * objectColor;
    FragColor = vec4(result, 1.0);
}
