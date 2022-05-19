/*
 * init.c
 * 
 *
 * Copyright (C) 2022  Leonard Steinhoff
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>


void usage_map(FILE* dest) {
	fprintf(dest, "Usage: brick [options] file\n");
	fprintf(dest, "		-v   Prints current version\n");
	fprintf(dest, "		-h	 Prints usage map\n");
	fprintf(dest, "		-o	 Changes output dir\n");
	fprintf(dest, "     -s   Runs binary in safemode\n");		

	if (dest == stderr)
		exit(1);
	exit(0);
}

char* parse_args(int argc, char* argv[]) {
	int i;
	char in_file[255];
	char out_file[255];
	while (i < argc) {
		if (argv[i][0] == '-') {
			switch (argv[i][1]) {
			case 'v':
				/*
				 * VERISON
				*/
				printf("Brick Version: v0.01a\n");
				break;
			case 'h':
				/*
				 * USAGE_MAP
				*/
				usage_map(stdout);
				break;
			case 'o':
				/*
				 * OUTPUT_DIR
				*/
				int next_val = i+1;
				if (next_val > argc && strlen(argv[next_val]) > 255)
					goto parse_err; 

				strcpy(out_file, argv[next_val]);
				break;
			default:
				goto parse_err;
				break;
			}
		} else {
			/*
			 * INPUT_DIR
			*/
			if (!access(argv[i], F_OK)) {
				perror("File does not exist!\n");
				goto parse_err;
			}
			if (strlen(argv[i] > 255))
				goto parse_err;

			strcpy(in_file, argv[i]);
		}
		i++;
	}
parse_err:
	/*
	 * INVALID_ARG_INPUT
	*/
	perror("Something went wrong while parsing!\n");
	usage_map(stderr);

	return 0;
}

int main(int argc, char* argv[]) {
	if (argc < 2)
		usage_map(stderr);

	parse_args( argc, argv );
	return 0;
}


