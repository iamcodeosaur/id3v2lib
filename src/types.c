/*
 * This file is part of the id3v2lib library
 *
 * Copyright (c) 2013, Lars Ruiz
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "types.h"

ID3v2_tag* new_tag()
{
    ID3v2_tag* tag = (ID3v2_tag*) calloc(sizeof(ID3v2_tag), 1);
    tag->tag_header = new_header();
    tag->frames = new_frame_list();
    return tag;
}

ID3v2_header* new_header()
{
    ID3v2_header* tag_header = (ID3v2_header*) calloc(sizeof(ID3v2_header), 1);
    if(tag_header != NULL)
    {
        memset(tag_header->tag, '\0', ID3_HEADER_TAG);
        tag_header->minor_version = 0x00;
        tag_header->major_version = 0x00;
        tag_header->flags = 0x00;
        memset(tag_header->tag, 0, ID3_HEADER_SIZE);
    }

    return tag_header;
}

ID3v2_frame* new_frame()
{
    ID3v2_frame* frame = (ID3v2_frame*) calloc(sizeof(ID3v2_frame), 1);
    return frame;
}

ID3v2_frame_list* new_frame_list()
{
    ID3v2_frame_list* list = (ID3v2_frame_list*) calloc(sizeof(ID3v2_frame_list), 1);
    if(list != NULL)
    {
        list->frame = NULL;
        list->next = NULL;
        list->start = NULL;
    }
    return list;
}

ID3v2_frame_text_content* new_text_content(int size)
{
    ID3v2_frame_text_content* content = (ID3v2_frame_text_content*) calloc(sizeof(ID3v2_frame_text_content), 1);
    content->data = (char*) malloc(size * sizeof(char));
    return content;
}

ID3v2_frame_comment_content* new_comment_content(int size)
{
    ID3v2_frame_comment_content* content = (ID3v2_frame_comment_content*) calloc(sizeof(ID3v2_frame_comment_content), 1);
    content->text = new_text_content(size - ID3_FRAME_SHORT_DESCRIPTION - ID3_FRAME_LANGUAGE);
    content->language = (char*) malloc(ID3_FRAME_LANGUAGE + sizeof(char));
    return content;
}

ID3v2_frame_apic_content* new_apic_content()
{
    ID3v2_frame_apic_content* content = (ID3v2_frame_apic_content*) calloc(sizeof(ID3v2_frame_apic_content), 1);
    return content;
}
