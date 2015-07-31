#include "shaders.h"

char* get_file_contents(const char *file_path, long* size)
{
	long filesize;
	FILE *file;
	char *new;
	
	file = fopen(file_path, "r");
	if(file == NULL)
	{
		fprintf(stderr, "Failed to open file: %s\n", file_path);
		return NULL;
	}

	fseek(file, 0, SEEK_END);
	filesize = ftell(file);
	if(size)
	{
		*size = filesize;
	}
	new = malloc(filesize + 1);
	if(!new)
	{
		fprintf(stderr, "Failed to allocate memory for file: %s\n",
		       file_path);
		fclose(file);
		return NULL;
	}
	fseek(file, 0, SEEK_SET);
	fread(new, filesize, 1, file);
	fclose(file);
	new[filesize] = '\0';
	return new;
}

shader* load_shader(const char *vertex_file, const char *fragment_file)
{
	shader *new;
	char *source, *log;
	long size;
	GLint value;
	GLsizei loglen;

	new = malloc(sizeof(*new));
	new->vertex = glCreateShader(GL_VERTEX_SHADER);
	new->fragment = glCreateShader(GL_FRAGMENT_SHADER);

	// Read and compile vertex shader
	source = get_file_contents(vertex_file, &size);
	glShaderSource(new->vertex, 1, &source, (GLint *)&size);
	glCompileShader(new->vertex);
	glGetShaderiv(new->vertex, GL_COMPILE_STATUS, &value);
	if(!value)
	{
		fprintf(stderr, "Failed to compile vertex shader: %s\n", vertex_file);
		glGetShaderiv(new->vertex, GL_INFO_LOG_LENGTH, &loglen);
		log = malloc(loglen);
		glGetShaderInfoLog(new->vertex, loglen, &loglen, log);
		fprintf(stderr, "%s", log);
		free(log);
		free(source);
		glDeleteShader(new->vertex);
		free(new);
		return NULL;
	}
	free(source);

	// Read and compile fragment shader
	source = get_file_contents(fragment_file, &size);
	glShaderSource(new->fragment, 1, &source, (GLint *)&size);
	glCompileShader(new->fragment);
	glGetShaderiv(new->fragment, GL_COMPILE_STATUS, &value);
	if(!value)
	{
		fprintf(stderr, "Failed to compile fragment shader: %s\n",
		        fragment_file);
		glGetShaderiv(new->fragment, GL_INFO_LOG_LENGTH, &loglen);
		log = malloc(loglen);
		glGetShaderInfoLog(new->fragment, loglen, &loglen, log);
		fprintf(stderr, "%s", log);
		free(log);
		free(source);
		glDeleteShader(new->fragment);
		glDeleteShader(new->vertex);
		free(new);
		return NULL;
	}
	free(source);

	new->program = glCreateProgram();
	glAttachShader(new->program, new->vertex);
	glAttachShader(new->program, new->fragment);
	glLinkProgram(new->program);

	glDeleteShader(new->fragment);
	glDeleteShader(new->vertex);

	return new;
}
