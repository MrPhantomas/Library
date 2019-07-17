CREATE TABLE [dbo].[Books] (
    [Id_book]  INT        IDENTITY (1, 1) NOT NULL,
    [b_name]   NCHAR (20) NOT NULL,
    [b_author] NCHAR (20) NOT NULL,
    [b_count]  INT        NULL,
    PRIMARY KEY CLUSTERED ([Id_book] ASC)
);

