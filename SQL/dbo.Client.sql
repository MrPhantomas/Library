CREATE TABLE [dbo].[Client] (
    [Id_people]    INT        IDENTITY (1, 1) NOT NULL,
    [p_name]       NCHAR (20) NOT NULL,
    [p_surname]    NCHAR (20) NULL,
    [p_patronimyc] NCHAR (20) NULL,
    [p_passport]   NCHAR (10) NOT NULL,
    [p_mobile]     NCHAR (15) NOT NULL,
    PRIMARY KEY CLUSTERED ([Id_people] ASC)
);

